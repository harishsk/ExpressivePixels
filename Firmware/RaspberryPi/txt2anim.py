import fire
from PIL import Image, ImageDraw, ImageFont
from animation import Animation, IFrame, DFrame, Color
from sys import platform

ANIMATION_WIDTH = 18
ANIMATION_HEIGHT = 18
ANIMATION_SIZE = (ANIMATION_WIDTH, ANIMATION_HEIGHT)

def get_palette(images):
    palette = []
    for image in images:
        w, h = image.size
        colors = [image.getpixel((i % w, i // w)) for i in range(w*h)]
        palette.extend(colors)
    palette = list(set(palette))
    return palette

def images_to_animation(images, delay):
    animation = Animation(None)
    palette = get_palette(images)
    palette_lookup  = {clr: index for index, clr in enumerate(palette)}
    animation.palette = [Color(r, g, b) for (r, g, b) in palette]

    frames = []
    for image in images:
        w, h = image.size
        colors = [image.getpixel((i % w, i // w)) for i in range(w*h)]
        indices = [palette_lookup[clr] for clr in colors]
        frame = IFrame(ord('I'), w * h, indices)
        frames.append(frame)

        frame = DFrame(ord('D'), delay)
        frames.append(frame)

    animation.frames_count = len(frames)
    animation.data = frames
    return animation    

def flashing_animation(text, font, color):
    images = []
    for char in text:
        img = Image.new('RGB', ANIMATION_SIZE)
        draw = ImageDraw.Draw(img)
        size = draw.textsize(char, font)
        x = (ANIMATION_WIDTH - size[0]) // 2
        y = (ANIMATION_HEIGHT - size[1]) // 2
        draw.text((x, y), char, color, font)
        images.append(img)
    return images

def get_black_frame():
    size = ANIMATION_SIZE
    img = Image.new('RGB', size)
    draw = ImageDraw.Draw(img)
    draw.rectangle((0, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT),  fill = (0,0,0))
    return img

def get_text_size(text, font):
    img_text = Image.new('RGB', ANIMATION_SIZE)
    draw = ImageDraw.Draw(img_text)
    text_size = draw.textsize(text, font)
    return text_size

def scrolling_animation(text, font, color):
    text_size = get_text_size(text, font)

    images = []
    img_text = Image.new('RGB', text_size)
    draw = ImageDraw.Draw(img_text)
    draw.text((0, 0), text, color, font)

    src_x = 0
    dst_x = ANIMATION_WIDTH - 1
    copy_width = 1
    black_frame = get_black_frame()
    images.append(black_frame)
    while True:
        img_temp = img_text.crop((src_x, 0, src_x + copy_width, ANIMATION_HEIGHT))
        img = Image.new('RGB', ANIMATION_SIZE)
        img.paste(img_temp, (dst_x, 0, dst_x + copy_width, ANIMATION_HEIGHT))
        images.append(img)

        copy_width = min(copy_width + 1, ANIMATION_WIDTH)
        dst_x = min(dst_x - 1, ANIMATION_WIDTH)
        dst_x = max(dst_x, 0)
        if dst_x == 0:
            src_x += 1
        if src_x > text_size[0]:
            break
    return images

def text_to_animation(text, font_size, color, delay, scroll=True, filename=None):
    if platform == 'win32':
        font_path = 'C:\\Windows\\Fonts\\segoeui.ttf'
    else:
        font_path = '/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf'
    font = ImageFont.truetype(font_path, font_size)
    if scroll:
        images = scrolling_animation(text, font, color)
    else:
        images = flashing_animation(text, font, color)

    animation = images_to_animation(images, delay)
    animation.name = text
    if not filename:
        filename = text
    Animation.save(filename, animation)



# e.g. 
# python txt2anim.py "HAPPY NEW YEAR" 15 "#00ff00" 500 True  "happy_new_year"
if __name__ == '__main__':
    fire.Fire(text_to_animation)


