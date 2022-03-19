#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int N, M;
  // Number Of Cities(Vertices)
  scanf("%d", &N);
  // Number Of Roads(Edges)
  scanf("%d", &M);
  int adjMat[N][M];

  // Number Of Affected Cities
  scanf("%d", &K);
  int a[K]; // Affected City
  for (int i = 0; i < K; ++i)
    scanf("%d", &a[i]);
  int u, v, l; // where l is the road between city u and v
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j)
      scanf("%d %d %d", &u, &v, &l);
    adjMat[u][v] = l;
  }
  return 0;
}
