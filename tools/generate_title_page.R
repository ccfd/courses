


library(htmltools)


body <-    tags$body(
    h1('My first heading'),
    p('My first paragraph, with some ',
      strong('bold'),
      ' text.'),
    div(id='myDiv', class='simpleDiv',
        'Here is a div with some attributes.')
)

doc <- tags$html(
    tags$head(
        tags$title('C-CFD')
    ),body
    

)
cat(as.character(doc))