<div align = "center" >
    <h1 >Atividade 1: Avaliação dos Algoritmos Minimax </h1>
    Anderson Rodrigues dos Santos  <br>
    Docente Michel Pires Da Silva  <br>
    Cetef-MG <i>Campus</i> Divinópolis
</div>

<div style="text-align: justify;">
    <h2>Introdução </h2>
    <p>
        A avaliação consiste na criação de um código que realiza uma comparação de 3 implementações discutida na sala de aula o MinMax1, MinMax2 e MinMax3. A ideia geral discutida, é visualizar o melhor custo computacional quando é submetido uma vetor de diferentes tamanhos e método de  aplicação (ordenado, crescente e decrescente).
    </p>
    <h2>Desenvolvimento </h2>
    <p>
        O planejamento do código teve a utilização da linguagem C++ e a implementação dos três algoritmos o MinMax1, MinMax2 e MinMax3 imposto pelo professor <a href="docs/Mimmax.pdf">[1]</a>.
    </p>
    <h3> Avaliação das Métodos</h3>
    <ol>
        <li>
        Utilização de diferentes tamanhos de entrada: 1000, 10.000, 100.000 e 500.000. Esses conjunto de dados deve ser gerado com valores variados entre 0 a 1000.
        </li>
        <li> 
            Cada algoritmo Minimax deve ser executado 10 vezes para cada tamanho de entrada. O tempo de execução obtido será a média dessas 10 execuções. 
        </li>
        <li>
            O mesmo conjunto de dados inicial deve ser utilizado para todas as avaliações de um determinado tamanho N de valores. Além disso, considere utilizar os mesmos dados para compor suas variações ordenadas, crescente e decrescente. 
        </li>
        <li>
            Elaboração uma planilha  e Gráficos:
            <ul>
                <li>
                    Elaborar uma planilha Excel para analisar as relações de tempo de forma de gráfica.
                </li>
                <li>
                    Recomendação: Utilizar o gnuplot para plotar os gráficos e disponibilizar o script junto com código no git.
                </li>
            </ul>
        </li>
        <li>
            Disponibilização do Código no Git.
        </li>
    </ol>
    <h3>Implementação do Código</h2>
        <h4>Arquivos</h4>
        <ul>
            <li>
                <b>src/</b> 
                <ol>
                    <li>
                        <b>File.cpp e File.hpp</b> 
                        <br>
                            Arquivos responsáveis de criar e escrever nas planilhas. <br><br>
                            - Funções e Variáveis:<br>

    private:
        string output_ordered, output_growing, output_decreasing;  //Guarda os endereço dos arquivos;

    public:
        File();  //Construtor da Classe, responsável por cria as planilhas
    
        void FileOrdered(int size, int mm1, int mm2, int mm3);
        void FileDecreasing(int size, int mm1, int mm2, int mm3);
        void FileGrowing(int size, int mm1, int mm2, int mm3);
        //As funções FileOrdered, FileDecreasing e FileGrowing são responsáveis por escrever os valores nos arquivo de linha por linha 

<br>                        
                    </li>
                    <li>
                        <b>MinMax.cpp e File.hpp</b><br>
                        São arquivos que tem função de  

    private:
        vector <int> min_max;
        int size;

        long MinMax1();
        long MinMax2();
        long MinMax3();

        void growingMinMax();
        void decreasingMinMax();

    public:
        MinMax();
        MinMax(int size);

        void run(File *file, int repeat = 10);
        void generate();
        void setSize(int size);

<br>
                    </li>
                </ul>
            </li>
        </ul>
    <h2>Referencia</h2>
    <p>
    <a href="docs/Mimmax.pdf">[1] - Documento da proposta da atividade</a><br>
    </p>

</div>
