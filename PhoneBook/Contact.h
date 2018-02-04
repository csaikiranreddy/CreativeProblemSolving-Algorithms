#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

typedef struct contact Contact;
struct contact
{
    char *fn;
    char *ln;
    char *mobile;
    Contact *next;
};

Contact *createContactNode(char *f, char *l, char *mobile);
Contact *addContact(Contact *head, char *f, char *l, char *m);
void listContacts(Contact *head);
void listNamesBeginningWith(Contact *head, char *pfn);
Contact *deleteContact(Contact *head, char fn[]);

#endif // CONTACT_H_INCLUDED
