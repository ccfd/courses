key=Sys.getenv("KLUCZ")

odszyfruj = function(sekret) rawToChar(as.raw(bitwXor(sekret,as.integer(charToRaw(key)))))
zaszyfruj = function(text,quiet=FALSE) {
  sekret = bitwXor(as.integer(charToRaw(text)),as.integer(charToRaw(key)))
  if (!quiet) cat("sekret = c(",paste(sekret,collapse=","),")\n")
  sekret
}
