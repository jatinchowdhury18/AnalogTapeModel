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
}

% manage title formats
\usepackage{titlesec}

\titleformat{\section}[block]{\fontsize{18pt}{1em}%
    \bodyfont\color{black}\bfseries\filcenter}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

\titleformat{\subsection}[hang]{\fontsize{16pt}{1em}%
    \bodyfont\color{black}\bfseries\raggedright}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

\titleformat{\subsubsection}[hang]{\fontsize{13pt}{1em}%
    \bodyfont\color{black}\bfseries\raggedright}{}{0em}%
    {}[\color{theme}{\titlerule[1pt]}]

% fancy footer
\usepackage{fancyhdr}
\usepackage[bottom]{footmisc}
\pagestyle{fancy}
\fancyhf{}
\fancyfoot[RO]{\color{gray}\textbf{\@pluginname} Plugin User Manual \textasciitilde \thepage/{\the\numexpr\value{page}+1\relax}}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{1pt}
\def\footrule{{\if@fancyplain\let\footrulewidth\plainfootrulewidth\fi
    % \vskip-\footruleskip\vskip-\footrulewidth
    \leavevmode\rlap{\color{theme}\rule{\textwidth}{\footrulewidth}}
    \vskip\footruleskip}}
