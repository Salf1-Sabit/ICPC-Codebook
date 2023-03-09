for (i = 0; i < MU_MAX;i++) {
  mu[i] = 1;
}

for (i = 2; i <= sqroot; i++) {
  if (mu[i] == 1) {
    // for each factor found, swap (+) and (-)
    for (j = i; j <= MU_MAX; j += i) {
      mu[j] *= (-1LL);
    }
    // square factor = 0
    for (j = i * i; j <= MU_MAX; j += i * i) {
      mu[j] = 0;
    }
  }
}
