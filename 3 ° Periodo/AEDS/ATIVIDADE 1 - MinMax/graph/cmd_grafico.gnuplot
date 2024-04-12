set datafile separator ","
set xlabel "Tamanho dos Vetores"
set ylabel "Media do Tempo em Nanometros(ns)"
set grid
set term png size 1200, 800
set key box outside 

#==============================================================================#
set title "Ordenado"
set output "graph/img/Ordenado.png"
plot "datagets/ordered.csv" using 1:2 with lines lw 2 lc 7 title "MinMax1", \
     "datagets/ordered.csv" using 1:3 with lines lw 2 lc 3 title "MinMax2", \
     "datagets/ordered.csv" using 1:4 with lines lw 2 lc 5 title "MinMax3"

set title "Decrescente"
set output "graph/img/Decrescente.png"
plot "datagets/decreasing.csv" using 1:2 with lines lw 2 lc 7 title "MinMax1", \
     "datagets/decreasing.csv" using 1:3 with lines lw 2 lc 3 title "MinMax2", \
     "datagets/decreasing.csv" using 1:4 with lines lw 2 lc 5 title "MinMax3"

set title "Crescente"
set output "graph/img/Crescente.png"
plot "datagets/growing.csv" using 1:2 with lines lw 2 lc 7 title "MinMax1", \
     "datagets/growing.csv" using 1:3 with lines lw 2 lc 3 title "MinMax2", \
     "datagets/growing.csv" using 1:4 with lines lw 2 lc 5 title "MinMax3"

#==============================================================================#

set title "MinMax1"
set output "graph/img/MinMax1.png"
plot "datagets/ordered.csv" using 1:2 with lines lw 2 lc 7 title "Ordenado", \
     "datagets/decreasing.csv" using 1:2 with lines lw 2 lc 3 title "Decrescente", \
     "datagets/growing.csv" using 1:2 with lines lw 2 lc 5 title "Crescente"

set title "MinMax2"
set output "graph/img/MinMax2.png"
plot "datagets/ordered.csv" using 1:3 with lines lw 2 lc 7 title "Ordenado", \
     "datagets/decreasing.csv" using 1:3 with lines lw 2 lc 3 title "Decrescente", \
     "datagets/growing.csv" using 1:3 with lines lw 2 lc 5 title "Crescente"

set title "MinMax3"
set output "graph/img/MinMax3.png"
plot "datagets/ordered.csv" using 1:4 with lines lw 2 lc 7 title "Ordenado", \
     "datagets/decreasing.csv" using 1:4 with lines lw 2 lc 3 title "Decrescente", \
     "datagets/growing.csv" using 1:4 with lines lw 2 lc 5 title "Crescente"
 