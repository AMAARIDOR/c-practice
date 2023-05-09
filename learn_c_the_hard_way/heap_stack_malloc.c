#include <stdio.h> // Standard Library for C
#include <assert.h> // Add assert macro for checking if memory exists
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Define some values from future reference 
#define MAX_DATA 512
#define MAX_ROWS 100

// Create Address struct
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// Create Database struct with Address and rows array with MAX_ROWS defined value
struct Database {
    struct Address rows[MAX_ROWS];
};

// Create Connection struct with FILE pointer and *db pointer for Database struct
struct Connection {
    FILE *file;
    struct Database *db;
};
	
// Function to format error
void die(const char *message) {
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
};

// Function to print items of the address of each database item
void Address_print(struct Address *addr) {
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// Function to load Data from already existing database
void Database_load(struct Connection *conn) {
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);

    if (rc != 1)
        die("Failed to load database.");
}

// Struct to open database when needed with the filename and mode as arguments
struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));

    if (!conn)
        die("Memory error");

    conn->db = malloc(sizeof(struct Database));

    if (!conn->db)
        die("Memory error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file");
    
    return conn;
}

// Function to close database
void Database_close(struct Connection *conn) {
    if (conn) {
        if (conn->file)
            fclose(conn->file);
        if (conn->db)
            free(conn->db);
        free(conn);
    }
}

// Function to write to database
void Database_write(struct Connection *conn) {
    rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	
	if (rc != 1) 
		die("Failed to write database.");

	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.");

}

// Function to create a database if doesn't exist already
void Database_create(struct Connection *conn) {
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = { .id = i, .set = 0 };
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

// Function to set a database with name, email
void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
	struct Address *addr = &conn->db->rows[id];

	if (addr->set)
		die("Already set, delete it first");

	addr->set = 1;
	// WARNING: bug, read the "How to Break it" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	// demonstrate the strncpy bug
	if (!res)
		die("Name copy failed");

	res = strncpy(addr->email, email, MAX_DATA);
	if (!res)
		die("Email copy failed");
}

// Function to fetch database details
void Database_get(struct Connection *conn, int id) {
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set");
	}
}

// Function to delete database 
void Database_delete(struct Connection *conn, int id) {
	struct Address addr = { .id = id, .set = 0 };
	conn->db->rows[id] = addr;
}

// Function to list database items and details
void Database_list(struct Connection *conn) {
	int i = 0;
	struct Database *db = conn->db;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
} 

// Main function
int main(int argc, char *argv[]) {
	if (argc < 3)
		die("USAGE: a.out <dbfile> <action> [action params]"); // Display with error formatting using die which has errno

	char *filename = argv[1]; // Consider the first argument as filename
	char action = argv[2][0]; // Consider the first letter of the second argument as the mode
	struct Connection *conn = Database_open(filename, action); // Open database with arguments from argv as mentioned before
	int id = 0; // Initialise ID

	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.");

	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if (argc != 4)
				die("Need an id to get");
				Database_get(conn, id);
				break;
		case 's':
			if (argc != 6)
				die("Need id, name, email to set");
				Database_set(conn, id, argv[4], argv[5]);
				Database_write(conn);
				break;
		case 'd':
			if (argc != 4)
				die("Need id to delete");
				Database_delete(conn, id);
				Database_write(conn);
				break;
		case 'l':
				Database_list(conn);
				break;
		default:
				die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;
}