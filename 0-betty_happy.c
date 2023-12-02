#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

/**
 * struct User - Structure to store username and password.
 * @username: Array to store the username.
 * @password: Array to store the password.
 */
struct User
{
	char username[MAX_USERNAME_LEN];
	char password[MAX_PASSWORD_LEN];
};

/**
 * users - Array to store registered users.
 */
struct User users[MAX_USERS];

/**
 * registerUser - Registers a new user.
 * @username: The username to register.
 * @password: The password to register.
 * @numUsers: Pointer to the number of registered users.
 *
 * Description: Registers a new user by storing their username and password.
 */
void registerUser(const char *username, const char *password, int *numUsers)
{
	if (*numUsers < MAX_USERS)
	{
		strcpy(users[*numUsers].username, username);
		strcpy(users[*numUsers].password, password);
		(*numUsers)++;
		printf("User registered successfully!\n");
	}
	else
	{
		printf("Cannot register more users. User limit reached.\n");
	}
}

/**
 * authenticateUser - Authenticates a user.
 * @username: The username for authentication.
 * @password: The password for authentication.
 * @numUsers: The number of registered users.
 * Return: 1 if authentication is successful, 0 otherwise.
 *
 * Description: Authenticates a user by comparing input username and password
 * with registered users' credentials.
 */
int authenticateUser(const char *username, const char *password, int numUsers)
{
	for (int i = 0; i < numUsers; ++i)
	{
		if (strcmp(users[i].username, username) == 0 &&
			strcmp(users[i].password, password) == 0)
		{
			return (1); /* Authentication successful */
		}
	}
	return (0); /* Authentication failed */
}

/**
 * main - Entry point of the program.
 * Return: 0 on successful execution.
 *
 * Description: Simulates user registration and authentication.
 */
int main(void)
{
	int numUsers = 0;

	registerUser("user1", "password123", &numUsers);

	/* Simulate user login */
	char inputUsername[MAX_USERNAME_LEN];
	char inputPassword[MAX_PASSWORD_LEN];

	/* Get input from user */
	printf("Enter username: ");
	scanf("%s", inputUsername);

	printf("Enter password: ");
	scanf("%s", inputPassword);

	/* Authenticate the user */
	if (authenticateUser(inputUsername, inputPassword, numUsers))
	{
		printf("Authentication successful. Access granted!\n");
	}
	else
	{
		printf("Authentication failed. Access denied.\n");
	}

	return (0);
}
