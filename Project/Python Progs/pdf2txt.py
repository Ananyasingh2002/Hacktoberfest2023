import os
from pdfreader import SimplePDFViewer
from pdfreader.viewer.pdfviewer import PageDoesNotExist

if not os.path.exists("temp"):
    os.mkdir("temp")

pdfpath = input("Enter the name of PDF file to convert: ")  # Provide the path for your pdf here
txtpath = input("Enter the name for the output TXT file: ")  # Provide the path for the output text file

BASEDIR = os.path.realpath("temp")
print(BASEDIR)

if not txtpath:
    txtpath = os.path.join(BASEDIR, os.path.basename(os.path.normpath(pdfpath)).replace(".pdf", "") + ".txt")

viewer = SimplePDFViewer(open(pdfpath, 'rb'))
text_content = ""

try:
    while True:
        viewer.render()
        text_content += viewer.canvas.text_content
        viewer.next()
except PageDoesNotExist as e:
    print(f"Error: {e}")
except StopIteration:
    pass

with open(txtpath, 'w', encoding='utf-8') as f:
    f.write(text_content)

print("Text extraction completed.")
