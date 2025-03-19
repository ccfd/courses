library(htmltools)

make_card <- function(title, short, im, long, address)
{
    div(class="w3-col s12 l6 w3-animate-bottom",
        div(class="w3-container w3-margin",
            div(class="w3-card-4",
                tags$header(class="w3-container w3-light-grey", h3(title)),
                div(class="w3-container",style="padding:16px 16px",
                    p(short),
                    hr(),
                    img(src=im, alt="icon", class="w3-left", style="padding:0px 12px"),
                    p(long)
                    )
                  ),
            tags$a(class="w3-button w3-block w3-dark-grey","Go to course", href=address)
           )
        )
}