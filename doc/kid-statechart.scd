Storage 
{
	{ Format 1.33 }
	{ GeneratedFrom TSCD-version-2.20 }
	{ WrittenBy diego }
	{ WrittenOn "" }
}

Document 
{
	{ Type "Statechart Diagram" }
	{ Name kid-statechart.scd }
	{ Author diego }
	{ CreatedOn "" }
	{ Annotation "" }
	{ Hierarchy True }
}

Page 
{
	{ PageOrientation Landscape }
	{ PageSize A4 }
	{ ShowHeaders False }
	{ ShowFooters False }
	{ ShowNumbers False }
}

Scale 
{
	{ ScaleValue 1 }
}

# GRAPH NODES

SCDOrState 1
{
	{ Name "Stand" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 2
{
	{ Name "Turning(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 14
{
	{ Name "Walking(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 22
{
	{ Name "Run" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 23
{
	{ Name "Start run(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 34
{
	{ Name "Couch" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 35
{
	{ Name "couching(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 36
{
	{ Name "standing(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 48
{
	{ Name "Crawling(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 60
{
	{ Name "Running(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 68
{
	{ Name "Stop_run(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 69
{
	{ Name "idle_standing(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 70
{
	{ Name "idle_couch(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 71
{
	{ Name "turn_running(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 94
{
	{ Name "go_up(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 95
{
	{ Name "jump_running(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

SCDOrState 96
{
	{ Name "jumping(i)" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

# GRAPH EDGES

SCDTransitionEdge 3
{
	{ Name "([<-] or [->]) in\ropposite direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 2 }
}

SCDTransitionEdge 10
{
	{ Name "i==n: dir = !dir" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 2 }
	{ Subject2 1 }
}

SCDTransitionEdge 15
{
	{ Name "(Shift+[->]or[<-]) in\rsame direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 14 }
}

SCDTransitionEdge 16
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 14 }
	{ Subject2 1 }
}

SCDTransitionEdge 30
{
	{ Name "[<-]or[->] in \rsame direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 23 }
}

SCDTransitionEdge 31
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 23 }
	{ Subject2 22 }
}

SCDTransitionEdge 37
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 36 }
	{ Subject2 1 }
}

SCDTransitionEdge 38
{
	{ Name "release[down]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 34 }
	{ Subject2 36 }
}

SCDTransitionEdge 39
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 35 }
	{ Subject2 34 }
}

SCDTransitionEdge 40
{
	{ Name "[down]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 35 }
}

SCDTransitionEdge 50
{
	{ Name "[<-]or[->] in\rsame direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 34 }
	{ Subject2 48 }
}

SCDTransitionEdge 51
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 48 }
	{ Subject2 34 }
}

SCDTransitionEdge 61
{
	{ Name "[->]or[<-] in\rsame direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 22 }
	{ Subject2 60 }
}

SCDTransitionEdge 62
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 60 }
	{ Subject2 22 }
}

SCDTransitionEdge 72
{
	{ Name "no key" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 69 }
}

SCDTransitionEdge 73
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 69 }
	{ Subject2 1 }
}

SCDTransitionEdge 74
{
	{ Name "[down]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 34 }
	{ Subject2 70 }
}

SCDTransitionEdge 75
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 70 }
	{ Subject2 34 }
}

SCDTransitionEdge 76
{
	{ Name "no key" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 22 }
	{ Subject2 68 }
}

SCDTransitionEdge 77
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 68 }
	{ Subject2 1 }
}

SCDTransitionEdge 78
{
	{ Name "[->]or[<-] in\ropposite direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 22 }
	{ Subject2 71 }
}

SCDTransitionEdge 79
{
	{ Name "i==n:\rdir = !dir" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 71 }
	{ Subject2 22 }
}

SCDTransitionEdge 92
{
	{ Name "[down]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 22 }
	{ Subject2 35 }
}

SCDTransitionEdge 97
{
	{ Name "[up]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 94 }
}

SCDTransitionEdge 98
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 94 }
	{ Subject2 1 }
}

SCDTransitionEdge 99
{
	{ Name "[up]+[->]or[<-] in\rsame direction" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 22 }
	{ Subject2 95 }
}

SCDTransitionEdge 100
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 95 }
	{ Subject2 22 }
}

SCDTransitionEdge 101
{
	{ Name "[up]+[dir]" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 96 }
}

SCDTransitionEdge 102
{
	{ Name "i==n" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 96 }
	{ Subject2 1 }
}

# VIEWS AND GRAPHICAL SHAPES

View 5
{
	{ Index "0" }
	{ Parent 0 }
}

RoundedBox 6
{
	{ View 5 }
	{ Subject 1 }
	{ Position 590 200 }
	{ Size 152 114 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 7
{
	{ View 5 }
	{ Subject 2 }
	{ Position 920 100 }
	{ Size 112 24 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 8
{
	{ View 5 }
	{ Subject 3 }
	{ FromShape 6 }
	{ ToShape 7 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 657 143 }
	{ Point 720 90 }
	{ Point 820 70 }
	{ Point 880 88 }
	{ NamePosition 770 80 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 12
{
	{ View 5 }
	{ Subject 10 }
	{ FromShape 7 }
	{ ToShape 6 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 908 112 }
	{ Point 850 170 }
	{ Point 740 190 }
	{ Point 666 190 }
	{ NamePosition 795 180 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 18
{
	{ View 5 }
	{ Subject 14 }
	{ Position 870 280 }
	{ Size 114 26 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 19
{
	{ View 5 }
	{ Subject 15 }
	{ FromShape 6 }
	{ ToShape 18 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 666 220 }
	{ Point 720 220 }
	{ Point 800 230 }
	{ Point 852 267 }
	{ NamePosition 760 225 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 20
{
	{ View 5 }
	{ Subject 16 }
	{ FromShape 18 }
	{ ToShape 6 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 813 280 }
	{ Point 780 280 }
	{ Point 700 270 }
	{ Point 666 248 }
	{ NamePosition 740 275 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 26
{
	{ View 5 }
	{ Subject 22 }
	{ Position 640 530 }
	{ Size 152 112 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 27
{
	{ View 5 }
	{ Subject 23 }
	{ Position 700 380 }
	{ Size 142 30 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 32
{
	{ View 5 }
	{ Subject 30 }
	{ FromShape 6 }
	{ ToShape 27 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 625 257 }
	{ Point 691 365 }
	{ NamePosition 669 306 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 33
{
	{ View 5 }
	{ Subject 31 }
	{ FromShape 27 }
	{ ToShape 26 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 694 395 }
	{ Point 662 474 }
	{ NamePosition 704 435 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 41
{
	{ View 5 }
	{ Subject 34 }
	{ Position 220 330 }
	{ Size 132 122 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 42
{
	{ View 5 }
	{ Subject 35 }
	{ Position 420 350 }
	{ Size 120 30 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 43
{
	{ View 5 }
	{ Subject 36 }
	{ Position 390 230 }
	{ Size 110 24 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 44
{
	{ View 5 }
	{ Subject 37 }
	{ FromShape 43 }
	{ ToShape 6 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 444 222 }
	{ Point 514 211 }
	{ NamePosition 477 207 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 45
{
	{ View 5 }
	{ Subject 38 }
	{ FromShape 41 }
	{ ToShape 43 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 286 291 }
	{ Point 370 242 }
	{ NamePosition 321 258 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 46
{
	{ View 5 }
	{ Subject 39 }
	{ FromShape 42 }
	{ ToShape 41 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 360 344 }
	{ Point 286 337 }
	{ NamePosition 324 331 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 47
{
	{ View 5 }
	{ Subject 40 }
	{ FromShape 6 }
	{ ToShape 42 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 525 257 }
	{ Point 437 335 }
	{ NamePosition 472 289 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 55
{
	{ View 5 }
	{ Subject 48 }
	{ Position 50 420 }
	{ Size 103 30 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 56
{
	{ View 5 }
	{ Subject 50 }
	{ FromShape 41 }
	{ ToShape 55 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 170 391 }
	{ Point 170 430 }
	{ Point 130 450 }
	{ Point 90 435 }
	{ NamePosition 156 458 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 57
{
	{ View 5 }
	{ Subject 51 }
	{ FromShape 55 }
	{ ToShape 41 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 80 405 }
	{ Point 80 380 }
	{ Point 130 360 }
	{ Point 154 360 }
	{ NamePosition 77 370 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 64
{
	{ View 5 }
	{ Subject 60 }
	{ Position 860 530 }
	{ Size 114 28 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 65
{
	{ View 5 }
	{ Subject 61 }
	{ FromShape 26 }
	{ ToShape 64 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 716 511 }
	{ Point 760 490 }
	{ Point 800 490 }
	{ Point 839 516 }
	{ NamePosition 784 473 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 66
{
	{ View 5 }
	{ Subject 62 }
	{ FromShape 64 }
	{ ToShape 26 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 832 544 }
	{ Point 790 560 }
	{ Point 740 560 }
	{ Point 716 530 }
	{ NamePosition 765 567 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 80
{
	{ View 5 }
	{ Subject 68 }
	{ Position 540 390 }
	{ Size 118 24 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 81
{
	{ View 5 }
	{ Subject 69 }
	{ Position 450 60 }
	{ Size 148 26 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 82
{
	{ View 5 }
	{ Subject 72 }
	{ FromShape 6 }
	{ ToShape 81 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 515 150 }
	{ Point 470 140 }
	{ Point 440 110 }
	{ Point 450 73 }
	{ NamePosition 455 125 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 83
{
	{ View 5 }
	{ Subject 73 }
	{ FromShape 81 }
	{ ToShape 6 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 496 73 }
	{ Point 540 90 }
	{ Point 550 110 }
	{ Point 552 143 }
	{ NamePosition 545 100 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 84
{
	{ View 5 }
	{ Subject 70 }
	{ Position 140 190 }
	{ Size 121 24 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 85
{
	{ View 5 }
	{ Subject 74 }
	{ FromShape 41 }
	{ ToShape 84 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 154 280 }
	{ Point 120 280 }
	{ Point 90 230 }
	{ Point 116 202 }
	{ NamePosition 90 255 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 86
{
	{ View 5 }
	{ Subject 75 }
	{ FromShape 84 }
	{ ToShape 41 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 164 202 }
	{ Point 200 220 }
	{ Point 210 250 }
	{ Point 190 269 }
	{ NamePosition 175 231 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 87
{
	{ View 5 }
	{ Subject 76 }
	{ FromShape 26 }
	{ ToShape 80 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 600 474 }
	{ Point 549 402 }
	{ NamePosition 545 441 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 88
{
	{ View 5 }
	{ Subject 77 }
	{ FromShape 80 }
	{ ToShape 6 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 543 378 }
	{ Point 575 257 }
	{ NamePosition 536 330 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 89
{
	{ View 5 }
	{ Subject 71 }
	{ Position 650 670 }
	{ Size 162 26 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 90
{
	{ View 5 }
	{ Subject 78 }
	{ FromShape 26 }
	{ ToShape 89 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 649 586 }
	{ Point 670 600 }
	{ Point 670 640 }
	{ Point 663 657 }
	{ NamePosition 759 624 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 91
{
	{ View 5 }
	{ Subject 79 }
	{ FromShape 89 }
	{ ToShape 26 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 624 657 }
	{ Point 590 640 }
	{ Point 590 600 }
	{ Point 621 586 }
	{ NamePosition 546 628 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 93
{
	{ View 5 }
	{ Subject 92 }
	{ FromShape 26 }
	{ ToShape 42 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 564 502 }
	{ Point 490 510 }
	{ Point 420 420 }
	{ Point 420 365 }
	{ NamePosition 455 465 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 103
{
	{ View 5 }
	{ Subject 94 }
	{ Position 620 10 }
	{ Size 88 22 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 104
{
	{ View 5 }
	{ Subject 97 }
	{ FromShape 6 }
	{ ToShape 103 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 590 143 }
	{ Point 590 100 }
	{ Point 590 50 }
	{ Point 609 21 }
	{ NamePosition 576 65 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 105
{
	{ View 5 }
	{ Subject 98 }
	{ FromShape 103 }
	{ ToShape 6 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 630 21 }
	{ Point 630 60 }
	{ Point 630 120 }
	{ Point 609 143 }
	{ NamePosition 645 89 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 106
{
	{ View 5 }
	{ Subject 95 }
	{ Position 370 600 }
	{ Size 160 26 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 107
{
	{ View 5 }
	{ Subject 99 }
	{ FromShape 26 }
	{ ToShape 106 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 564 530 }
	{ Point 500 530 }
	{ Point 410 560 }
	{ Point 410 587 }
	{ NamePosition 390 537 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 108
{
	{ View 5 }
	{ Subject 100 }
	{ FromShape 106 }
	{ ToShape 26 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 450 600 }
	{ Point 520 600 }
	{ Point 550 590 }
	{ Point 564 572 }
	{ NamePosition 492 581 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

RoundedBox 109
{
	{ View 5 }
	{ Subject 96 }
	{ Position 320 150 }
	{ Size 116 24 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 110
{
	{ View 5 }
	{ Subject 101 }
	{ FromShape 6 }
	{ ToShape 109 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 514 168 }
	{ Point 470 150 }
	{ Point 430 140 }
	{ Point 378 145 }
	{ NamePosition 447 159 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 111
{
	{ View 5 }
	{ Subject 102 }
	{ FromShape 109 }
	{ ToShape 6 }
	{ Curved True }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 4 }
	{ Point 356 162 }
	{ Point 380 180 }
	{ Point 460 190 }
	{ Point 514 190 }
	{ NamePosition 417 190 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--10*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

