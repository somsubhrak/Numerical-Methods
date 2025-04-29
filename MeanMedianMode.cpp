#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int r, c = 5, i, b = -1, mode_index = 0;
	float **a, sum = 0.0, mean, f = 0.0, median, mode = 0.0, cumulative_freq = 0.0, sum_squared_diff, std_dev = 0.0, sumxf = 0.0;

	printf("Enter number of data: ");
	scanf_s("%d", &r);

	// Dynamically allocate memory
	a = (float**)malloc(r * sizeof(float*));
	for (i = 0; i < r; i++) {
		a[i] = (float*)malloc(c * sizeof(float));
	}

	// Input data and calculate midpoints and xf values
	for (i = 0; i < r; i++) {
		printf("Enter lower limit, upper limit, frequency of data %d\n", i + 1);
		scanf_s("%f", &a[i][0]); // lower limit
		scanf_s("%f", &a[i][1]); // upper limit
		scanf_s("%f", &a[i][2]); // frequency
		a[i][3] = (a[i][0] + a[i][1]) / 2.0; // midpoint
		a[i][4] = a[i][3] * a[i][2];         // xf
		sum += a[i][4];                      // cumulative xf
		f += a[i][2];                        // total frequency
		sumxf += a[i][4] * a[i][3];			//x2f
		if (a[i][2] > a[mode_index][2])		// modal class (highest)
			mode_index = i;
	}

	int ch = 1;
	printf("1)Mean\n2)Median\n3)Mode\n4)Standard deviation\n5)Press 0 to exit");
	while (ch)
	{
		printf("\nEnter choice:");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1: // Calculate mean
			mean = sum / f;
			printf("Mean: %f\n", mean);
			break;
		case 2: // Calculate median
			cumulative_freq = 0.0;
			for (i = 0; i < r; i++)
			{
				cumulative_freq += a[i][2]; // cumulative frequency
				if (cumulative_freq >= f / 2) {
					b = i;		//median class
					break;
				}
			}
			if (b != -1) {
				float l = a[b][0];
				//float cf_prev = (b == 0) ? 0 : cumulative_freq - a[b][2];
				float cf_prev = cumulative_freq - a[b][2];
				float h = a[b][1] - a[b][0];
				median = l + ((f / 2 - cf_prev) / a[b][2]) * h;
				printf("Median: %f\n", median);
			}
			else
				printf("Median cant be calculated\n");
			break;

		case 3: // Calculate mode
			if (mode_index > 0 && mode_index < r - 1) {
				float f1 = a[mode_index][2];
				float f2 = a[mode_index - 1][2];
				float f3 = a[mode_index + 1][2];
				float l = a[mode_index][0];
				float h = a[mode_index][1] - a[mode_index][0];
				mode = l + ((f1 - f2) / (2 * f1 - f2 - f3)) * h;
				printf("Mode: %f\n", mode);
			}
			else {
				printf("Mode cannot be calculated\n");
			}
			break;

		case 4:
			std_dev = sqrt(sumxf / f - ((sum / f) * (sum / f)));
			printf("The standard deviation is: %f\n", std_dev);
			break;

		default: printf("Wrong choice\n");

		}

	}
	// Free allocated memory
	for (i = 0; i < r; i++) {
		free(a[i]);
	}
	free(a);

}
