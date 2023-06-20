//#include <stdio.h>
//
// 牛顿插值多项式
//double newton_interpolation(double x[], double y[], int n, double value) {
//    double result = 0.0;
//    double temp[n][n];
//    int i, j, k;
//
//     初始化差商表
//    for (i = 0; i < n; i++) {
//        temp[i][0] = y[i];
//    }
//
//     生成差商表
//    for (i = 1; i < n; i++) {
//        for (j = 0; j < n - i; j++) {
//            temp[j][i] = (temp[j + 1][i - 1] - temp[j][i - 1]) / (x[j + i] - x[j]);
//        }
//    }
//
//     计算插值多项式的值
//    for (i = 0; i < n; i++) {
//        double term = temp[0][i];
//        for (j = 0; j < i; j++) {
//            term *= (value - x[j]);
//        }
//        result += term;
//    }
//
//    return result;
//}
//
//int main() {
//    double x[] = { 0.2, 0.4, 0.6, 0.8, 1.0 };
//    double y[] = { 0.98, 0.92, 0.81, 0.64, 0.38 };
//    int n = sizeof(x) / sizeof(x[0]);
//
//     生成插值点
//    double start = 0.2;
//    double end = 1.0;
//    double step = 0.01;
//
//     打印插值结果
//    printf("x\t\tf(x)\n");
//    printf("-----------------\n");
//    for (double value = start; value <= end; value += step) {
//        double result = newton_interpolation(x, y, n, value);
//        printf("%.2f\t\t%.4f\n", value, result);
//    }
//
//     使用gnuplot库绘制图像
//    file* gnuplotpipe = _popen("gnuplot -persistent", "w");
//    if (gnuplotpipe) {
//        fprintf(gnuplotpipe, "plot '-' with lines\n");
//        for (double value = start; value <= end; value += step) {
//            double result = newton_interpolation(x, y, n, value);
//            fprintf(gnuplotpipe, "%lf %lf\n", value, result);
//        }
//        fprintf(gnuplotpipe, "e\n");
//        fflush(gnuplotpipe);
//        _pclose(gnuplotpipe);
//    }
//
//    return 0;
//}
