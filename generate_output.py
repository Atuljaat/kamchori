from PIL import Image, ImageDraw, ImageFont


def output_to_image(output_text, output_path):
    try:
        # font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", 20)
        font = ImageFont.truetype("DejaVuSansMono.ttf", 20)
    except OSError:
        font = ImageFont.load_default()

    lines = output_text

    max_width = max(font.getbbox(line)[2] - font.getbbox(line)[0] for line in lines) + 20
    line_height = max(font.getbbox(line)[3] - font.getbbox(line)[1] for line in lines) + 4
    total_height = line_height * len(lines) + 10

    image = Image.new("RGB", (max_width, total_height), color="black")
    draw = ImageDraw.Draw(image)

    y = 5
    for line in lines:
        draw.text((5, y), line, font=font, fill="white")
        y += line_height

    image.save(output_path, dpi=(96, 96))
    return output_path
