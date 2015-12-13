# -*- coding: utf-8 -*-
import sys
import os
import shlex
import sphinx_rtd_theme

sys.path.insert(0, os.path.abspath('.'))

# -- General configuration ------------------------------------------------
extensions = []
templates_path = ['_templates']
source_suffix = '.rst'
#source_encoding = 'utf-8-sig'
master_doc = 'index'

project = u'Linked Lists'
copyright = u'2015, Roie R. Black'
author = u'Roie R. Black'
version = '0.1'
release = '0.1'
language = None
today_fmt = '%B %d, %Y'

exclude_patterns = ['_build', '_venv']
pygments_style = 'sphinx'
todo_include_todos = False

# -- Options for HTML output ----------------------------------------------
html_theme = 'sphinx_rtd_theme'
#html_theme_options = {}
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
#html_title = None
#html_short_title = None
#html_logo = None
#html_favicon = None
html_static_path = ['_static']
html_last_updated_fmt = '%b %d, %Y'
html_show_sphinx = True
html_show_copyright = True

# -- Options for LaTeX output ---------------------------------------------

latex_elements = {
'papersize': 'letterpaper',
'pointsize': '11pt',

# Latex figure (float) alignment
'figure_align': 'htbp',
}

latex_documents = [
  (master_doc, 'mandlebrot.tex', u'Bitmapped Mandlebrot',
   u'Roie R. Black', 'manual'),
]
