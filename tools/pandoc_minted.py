#!/usr/bin/env python3
"""A pandoc filter to use minted for typesetting code in the LaTeX mode."""

# This file is copied from megabyde/pandoc-minted repo
#    which is under a mixed open-source license

from string import Template

from pandocfilters import Header, RawBlock, RawInline, toJSONFilters


def unpack_code(value):
    """Unpack the body and language of a pandoc code element."""
    (_, classes, attributes), contents = value

    language = classes[0] if classes else "text"
    params = ", ".join("=".join(kv) for kv in attributes)

    return {
        "contents": contents,
        "language": language,
        "attributes": params,
    }


def fragile(key, value, format, meta):
    """Make headers/frames fragile."""
    if format != "beamer":
        return None

    if key == "Header":
        level, meta, contents = value
        # Add the attribute
        meta[1].append("fragile")
        return Header(level, meta, contents)
    return None


def minted(key, value, format, meta):
    """Use minted for code in LaTeX."""
    if format not in ("latex", "beamer"):
        return None

    if key == "CodeBlock":
        template = Template("\\begin{minted}[$attributes]{$language}\n$contents\n\\end{minted}")
        klass = RawBlock
    elif key == "Code":
        template = Template("\\mintinline[$attributes]{$language}{$contents}")
        klass = RawInline
    else:
        return None

    text = template.substitute(unpack_code(value))
    return klass("latex", text)


if __name__ == "__main__":
    toJSONFilters([fragile, minted])
