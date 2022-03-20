#!/usr/bin/env python3

import sys
from PyPDF2 import PdfFileReader, PdfFileWriter

fname = sys.argv[1]
# page = int(sys.argv[2]) - 1     # page starts at 0

ifstrm = PdfFileReader(fname)
ofstrm = PdfFileWriter()

ofstrm.addPage(ifstrm.getPage(16))
ofstrm.addPage(ifstrm.getPage(17))
ofstrm.addPage(ifstrm.getPage(18))
ofstrm.addPage(ifstrm.getPage(19))
ofstrm.addPage(ifstrm.getPage(20))
ofstrm.addPage(ifstrm.getPage(21))

with open(f"subPage.pdf", "wb") as f:
    ofstrm.write(f)
