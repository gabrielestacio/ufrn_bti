int m1[3][3];
int m2[3][3];
int mr[3][3];

function main(){
    //consertar
    print("Digite o número de linhas: ");
    int linhas := read();
    print("Digite o número de colunas: ");
    int colunas := read();
    print("PRIMEIRA MATRIZ\n");
    for(int i := 0; i< linhas; i++){
        for(int j := 0; j< colunas; j++){
            print("Digite o valor do " + j + "º valor da linha " + i +"\n");
            m1.[i][j] := read();
        }
    }
    print("SEGUNDA MATRIZ");
    for(int i := 0; i< linhas; i++){
        for(int j := 0; j< colunas; j++){
            print("Digite o valor do " + j + "º valor da linha " + i +"\n");
            m2.[i][j] := read();
        }
    }
    //somando
    for(int i := 0; i < linhas; i++){
        for(int j := 0; j < colunas; j++){
            for(int k := 0; k < colunas; k++){
                mr.[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}