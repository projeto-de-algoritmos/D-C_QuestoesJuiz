#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#define X second
#define Y first
#define MP make_pair
using namespace std;
typedef pair<double, double> point;

// Função de comparação para ordenar pontos pelo eixo X
int comp(point A, point B) { return A.X < B.X; }

// Função principal para encontrar o par mais próximo
double closest_pair(vector<point> P) {
    int n = P.size();
    
    // Ordena os pontos pelo eixo X
    sort(P.begin(), P.end(), comp);

    // Inicializa a menor distância como um valor grande
    double best = 100000.0;

    // Cria uma "caixa" (strip) para armazenar pontos relevantes
    set<point> box;
    box.insert(P[0]);

    // Índice para percorrer a "caixa"
    int left = 0;

    // Itera sobre os pontos restantes
    for (int i = 1; i < n; i++) {
        // Remove pontos da "caixa" que estão fora da faixa relevante
        while (left < i && P[i].X - P[left].X > best) {
            box.erase(P[left++]);
        }

        // Itera sobre os pontos na "caixa" com base na coordenada Y
        for (set<point>::iterator it =
                 box.lower_bound(MP(P[i].Y - best, P[i].X - best));
             it != box.end() && P[i].Y + best >= (*it).Y; it++) {
            // Atualiza a menor distância se encontrar um par mais próximo
            best = min(best, hypot(P[i].X - (*it).X, P[i].Y - (*it).Y));
        }

        // Adiciona o ponto atual à "caixa"
        box.insert(P[i]);
    }

    // Retorna a menor distância encontrada
    return best;
}

int main() {
    int quantidade;
    while (scanf("%d", &quantidade) && quantidade) {
        vector<point> entrada;
        
        // Lê os pontos de entrada
        for (int i = 0; i < quantidade; i++) {
            double x1, y1;
            scanf("%lf %lf", &x1, &y1);
            entrada.push_back(MP(y1, x1));  // Inverte as coordenadas para ordenação por X
        }

        // Chama a função para encontrar o par mais próximo
        double resultado = closest_pair(entrada);

        // Imprime o resultado, considerando o caso de distância infinita
        if (resultado > 10000.0 && fabs(resultado - 10000.0) > 1e-5)
            printf("INFINITY\n");
        else
            printf("%.4lf\n", resultado);
    }

    return 0;
}
