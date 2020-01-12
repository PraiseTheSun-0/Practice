#include <iostream>

char *myStrtok(char *string, const char *delim)
{
	static char *start;
	static char *end;
	int i = 0, k = 0;
	bool found = false;
	static bool ended;
	if (string != NULL)start = string;
	else if(!ended)start = &end[1];
	else return nullptr;
	ended = false;
	while (!found && start[i] != '\0')
	{
		k = 0;
		while (start[i] != delim[k]) {
			k++;
			if (delim[k] == '\0') {
				ended = true;
				break;
			}
		}
		if (!ended)i++;
		else
		{
			found = true;
			start = &start[i];
		}
	}
	if (!found)return nullptr;
	found = false;
	i = 0;
	while(!found && start[i]!='\0')
	{
		ended = false;
		k = 0;
		while(start[i]!=delim[k]){
			k++;
			if (delim[k] == '\0') {
				ended = true;
				break;
			}
		}
		if (ended) {
			ended = false;
			i++;
			if (start[i] == '\0')ended = true;
		}
		else
		{
			found = true;
			end = &start[i];
			end[0] = '\0';
		}
	}
	return start;
}

int main()
{
	char str[200];
	char del[20];
	std::cin.getline(str,200);
	std::cin.getline(del, 20);
	
	char *cOut = myStrtok(str, del);
	while (cOut != NULL)
	{
		std::cout << cOut << std::endl;
		cOut = myStrtok(NULL, del);
	}
	return 0;
}
