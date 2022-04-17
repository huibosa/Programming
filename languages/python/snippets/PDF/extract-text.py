#!/usr/bin/env python3

import pdfplumber

fname = "a.pdf"

with pdfplumber.open(fname) as pdf:
    for page in pdf.pages:
        text = page.extract_text()
        file = open("extractText.txt", mode="a")
        file.write(text)
