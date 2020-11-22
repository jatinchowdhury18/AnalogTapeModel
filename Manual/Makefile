SOURCES = ChowTapeManual.tex manual.cls
TEX_FLAGS = 

PDFS = $(patsubst %.tex, %.pdf, $(SOURCES))

.PHONY: clean

%.pdf: %.tex
	xelatex $(TEX_FLAGS) $<

all: $(PDFS)

clean:
	rm -f *.{log,pdf,out,aux,fls,fdb*,sync*}

deploy: $(PDFS)
	scp ChowTapeManual.pdf jatin@ccrma-gate.stanford.edu:~/Library/Web/chowdsp/Products
