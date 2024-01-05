int main() {
	int x = 6;
	int y = 10;

}

int swap(int *a, int *b)
{
	int j = a;
	a = &b;
	b = j;
	return a, b;
}