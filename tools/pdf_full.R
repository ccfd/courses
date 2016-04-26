
pdf_full = function( ... ) {
  ret = pdf_document(template = "tools/pdf_small_template.tex", ...)
  ret$post_processor = function(yaml, input, output,...) {
    post_doc = pdf_document(
      pandoc_args = c("--variable",paste("pdffile",output,sep=":")),
      template = "tools/pdf_full_template.tex"
    )
    cat("And now running again ",input," with ",output,"\n")
    ret = render(input, post_doc)
    file.rename(ret, output)
    output
  }
  ret
}
