library(htmltools)

h = tags$head( tags$title("C-CFD") )

make_div = function(title, short, im, long)
{
  d=div(class="w3-cell-row w3-animate-bottom",
        div(class="w3-mobile", style="padding:16px",
            div(class="w3-card-4",
                tags$header(class="w3-container w3-light-grey", h3(title)),
                div(class="w3-container",style="padding:16px 16px",
                    p(short),
                    hr(),
                    img(src=im, alt="icon", class="w3-left", style="padding:0px 12px"),
                    p(long)
                    )
                ),
            tags$button(class="w3-button w3-block w3-dark-grey","Go to course")
          )
        )
  return(d)
}


divs=c()
for(i in 1:3)
{
  d = make_div("Informatyka I", "Basic course in C programming", "figures/computer.png","...")
  divs = c(divs, d)
}



body = tags$body(tags$link(rel="stylesheet", href="https://www.w3schools.com/lib/w3.css"),
                 divs[1])

doc <- tags$html(h, body)

cat(as.character(doc))

#write(as.character(doc), "test_gen.html")

