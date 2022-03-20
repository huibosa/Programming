#!/usr/bin/env python3


from PyPDF2 import PdfFileReader, PdfFileWriter
import sys


def merge_pdfs(fnames, output):
    pdf_writer = PdfFileWriter()
    input1 = PdfFileReader(fnames[0])
    input2 = PdfFileReader(fnames[1])

    # pdf1 and pdf2 always has equal pages
    max = input1.getNumPages()
    cnt1 = 0
    cnt2 = 0

    while cnt1 < max or cnt2 < max:
        if cnt1 <= cnt2:
            pdf_writer.addPage(input1.pages[cnt1])
            cnt1 = cnt1 + 1
        else:
            pdf_writer.addPage(input2.pages[cnt2])
            cnt2 = cnt2 + 1

    # Write out the merged PDF
    with open(output, "wb") as out:
        pdf_writer.write(out)


if __name__ == "__main__":
    fnames = [sys.argv[1], sys.argv[2]]
    merge_pdfs(fnames, output="merged.pdf")
