import img2pdf
import os

# Supported image file extensions
image_extensions = ['.jpg', '.jpeg', '.png', '.gif', '.bmp', '.tiff']

filepath = input("Enter the file or directory path: ")

if os.path.isdir(filepath):
    imgs = []
    for fname in os.listdir(filepath):
        if any(fname.lower().endswith(ext) for ext in image_extensions):
            path = os.path.join(filepath, fname)
            if os.path.isfile(path):
                imgs.append(path)
    if imgs:
        with open("output.pdf", "wb") as f:
            f.write(img2pdf.convert(imgs))
    else:
        print("No supported image files found in the directory.")
elif os.path.isfile(filepath) and any(filepath.lower().endswith(ext) for ext in image_extensions):
    with open("output.pdf", "wb") as f:
        f.write(img2pdf.convert(filepath))
else:
    print("Invalid file or directory path or the input file is not a supported image format.")
