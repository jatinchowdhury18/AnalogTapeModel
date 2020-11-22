\LoadClass{article}

% for figures
\usepackage{graphicx}

% Needed to manage colors
\RequirePackage{xcolor}
\colorlet{theme}{black}

% Manage name
\newcommand*{\pluginname}[1]{\def\@pluginname{#1}}

% Manage spacing
\def\newpar{\newline\newline}
\usepackage[skip=2.5pt]{caption}
\setlength{\belowcaptionskip}{-12pt}

% Needed to manage fonts
\RequirePackage[default,opentype]{sourcesanspro}
\usepackage[sfdefault,light]{roboto}
\newcommand*{\bodyfont}{\roboto} % {\sourcesanspro}

\newcommand\boldtheme[1]{\textcolor{theme}{\textbf{#1}}}

% format hyperlinks
\usepackage{hyperref}
\hypersetup{
    colorlinks=true,
    linkcolor=blue,
    filecolor=magenta,      
    urlcolor=blue,
    pdfstartview=FitW
}

% manage title formats
\usepackage{titlesec}

\titleformat{\section}[block]{\fontsize{18pt}{1em}%
    \bodyfont\color{black}\bfseries\filcenter}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

\titleformat{\subsection}[hang]{\fontsize{16pt}{1em}%
    \bodyfont\color{black}\bfseries\raggedright}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

\titleformat{\subsubsection}[hang]{\fontsize{11pt}{1em}%
    \bodyfont\color{black}\bfseries\raggedright}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

% fancy footer
\usepackage{fancyhdr}
\usepackage[bottom,flushmargin]{footmisc}
\pagestyle{fancy}
\fancyhf{}
\fancyfoot[RO]{\color{gray}\textbf{\@pluginname} Plugin User Manual \textasciitilde \ {\the\numexpr2*\value{page}-1\relax}/{\the\numexpr2*\value{page}\relax}}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{1pt}
\def\footrule{{\if@fancyplain\let\footrulewidth\plainfootrulewidth\fi
    \leavevmode\rlap{\color{theme}\rule{\textwidth}{\footrulewidth}}
    \vskip\footruleskip}}
