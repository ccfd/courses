
pdf_full = function( ... ) {
  pandoc_args = c("--resource-path",paste(".",TOOLS,sep=":"))
  ret = pdf_document(
    template = "pdf_small_template.tex",
    pandoc_args = pandoc_args,
    ...
  )
  ret$post_processor = function(yaml, input, output,...) {
    post_doc = pdf_document(
      pandoc_args = c("--variable",paste("pdffile",output,sep=":"), pandoc_args),
      template = "pdf_full_template.tex"
    )
    cat("And now running again ",input," with ",output,"\n")
    ret = render(input, post_doc)
    file.rename(ret, output)
    output
  }
  ret
}
