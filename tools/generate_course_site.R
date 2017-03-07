
library(htmltools)

doc<-tags$html(
        tags$title("Informatyka I"),
        tags$link(rel="stylesheet", href="https://www.w3schools.com/lib/w3.css"),
        tags$body(
            tags$div(class="w3-center", tags$h1("Informatyka I")),
            tags$div(class="w3-container",
                tags$ul(class="w3-ul w3-hoverable",
                    tags$li(ref="info1_lab01.html", "lab 1"),
                    tags$li(ref="info1_lab02.html", "lab 2"),
                    tags$li(ref="info1_lab03.html", "lab 3"),
                    tags$li(ref="info1_lab04.html", "lab 4"),
                    tags$li(ref="info1_lab04.html", "lab 6"),
                    tags$li(ref="info1_lab04.html", "lab 7"),
                    tags$li(ref="info1_lab04.html", "lab 9"),
                    tags$li(ref="info1_lab04.html", "lab 10")
                )
            )
        )
    )

#cat(as.character(doc))
write(as.character(doc), "_site/info1.html")