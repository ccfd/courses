
%.pdf : %.md
	tools/pdf_full $<

%.pdf : %.Rmd
	tools/pdf_full $<

