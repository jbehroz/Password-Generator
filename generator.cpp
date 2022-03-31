#include "generator.h"
#include <iostream>


/*
This is the constructor for the class. It is expected that the user will never
call anything but this constructor, as it has all of the functionality needed to 
change, generate, and print the password. First, I defined the individual pools
for the upper/lowercase characters, special characters, and numbers. Then, the 
program intro prints out and invites the user to change the default settings if 
they choose. Should they go with the default settings, a password is generated 
and outputted before the program ends. The default settings are 9 variables that
control various parts of the pool for the password generation and the final 
password, with 1 being enabled and 0 being disabled if applicable:
1. p_length = 12;       Password Length
2. special_chars = 1;   Special Charaters in the password pool
3. nums = 1;            Numbers in ""
4. a_u = 1;             Uppercase Characters in ""
5. a_l = 1;             Lowercase Characters in ""

After generating the password, these variables define whether or not the 
program adds a specific type of character into the password, replacing one of 
the previous characters:
1. force_SC = 0;        Adds a special character to the password after generation
2. force_NC = 0;        Adds a number to ""
3. force_UC = 0;        Adds an uppercase character to ""
4. force_LC = 0;        Adds a lowercase character to ""

The password is generated by the following logic:
1. Add all of the enabled character types into a pool of characters;
2. In a for loop as long as p_length, grab a random character from the entire pool
and add that character to the end of the password each run;
3. After the password is generated, check for a character to be forced into the 
password;
4. Replace a random character in the password with a character from the pool 
being forced;
5. Print the password;

The code that forced a character does not consider whether the user enabled that
pool earlier in the program; it presumes that the user fully intended to not 
include that pool except for one character in the password for whatever reason.

There are a couple ways to intentionally crash this program if the user wished:
After deciding to change a setting, put a character that is not a number or c 
Make the password length 0 
Have an empty pool and force a character

*/
Generator::Generator()
{
    l_c_p = "abcdefghijklmnopqrstuvwxyz";
    u_c_p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    s_c_p = "!@#$\%^&*()-=_+[]{}\\;:\'\",<.>/?";
    n_p = "0123456789";
    std::string input;
    std::cout << "Welcome to the password generator.\n";
    std::cout << "This program generates a password with predefined settings "
    << "that you can change if you do not agree with the default settings.\n";
    std::cout << "The default conditions are:\n";
    std::cout << "1. Password Length:                 12\n";
    std::cout << "2  Special Characters:              ON\n";
    std::cout << "3. Numbers:                         ON\n";
    std::cout << "4. Uppercase Characters:            ON\n";
    std::cout << "5. Lowercase Characters:            ON\n";
    std::cout << "6. Guaranteed Special Character:   OFF\n";
    std::cout << "7. Guaranteed Number:              OFF\n";
    std::cout << "8. Guaranteed Uppercase Character: OFF\n";
    std::cout << "9. Guaranteed Lowercase Character: OFF\n";
    std::cout << "If you agree with all of these, enter c to continue or n to"
    << " change any of these.\n";
    std::getline(std::cin, input);
    password = "_";
    pool = "_";
    special_chars = 1;
    nums = 1;
    a_u = 1;
    a_l = 1;
    force_SC = 0;
    force_NC = 0;
    force_UC = 0;
    force_LC = 0;
    p_length = 12;
    if (input == "n")
    {
        while (input != "c")
        {
            std::cout << "Enter the setting number you would like to change, or"
            << " c to generate the password\n";
            std::getline(std::cin, input);
            int iinput = 0;
            if (input != "c") 
            {
                iinput = std::stoi(input);
                switch (iinput)
                {
                    case 0:
                        break;
                    case 1:
                        std::cout << "Enter a new password length.\n";
                        std::getline(std::cin, input);
                        p_length = std::stoi(input);
                        std::cout << "The new password length is " << input \
                        << std::endl;
                        break;
                    case 2:
                        std::cout << "Special Characters are now off.\n";
                        special_chars = 0;
                        break;
                    case 3:
                        std::cout << "Numbers are now off\n";
                        nums = 0;
                        break;
                    case 4:
                        std::cout << "Uppercase Characters are now off.\n";
                        a_u = 0;
                        break;
                    case 5:
                        std::cout << "Lowercase Characters are now off.\n";
                        a_l = 0;
                        break;
                    case 6:
                        std::cout << "The password now has a guaranteed Special"
                        << "Character.\n";
                        force_SC = 1;
                        break;
                    case 7:
                        std::cout << "The password now has a guaranteed " 
                        << "Number\n";
                        force_NC = 1;
                        break;
                    case 8:
                        std::cout << "The password now has a guaranteed " 
                        << "Uppercase Character.\n";
                        force_UC = 1;
                        break;
                    case 9:
                        std::cout << "The password now has a guaranteed " 
                        << "Lowercase Character.\n";
                        force_LC = 1;
                        break;
                }
            }
        }
    };
    if (special_chars == 1) {pool = pool + s_c_p;};
    if (nums == 1) {pool = pool + n_p;};
    if (a_u == 1) {pool = pool + u_c_p;};
    if (a_l == 1) {pool = pool + l_c_p;};
    std::cout << "Pool is: " << pool << std::endl;
    pool.erase(pool.begin());
    for (int i = 0; i < p_length; i++)
        {
            password += pool[std::rand() % pool.length()];
        }
    password.erase(password.begin());
    if (force_SC == 1) 
    {
        password[std::rand() % password.length()] = \
        s_c_p[std::rand() % s_c_p.length()];
    }
    if (force_NC == 1) 
    {
        password[std::rand() % password.length()] = \
        n_p[std::rand() % n_p.length()];
    }
    if (force_UC == 1) 
    {
        password[std::rand() % password.length()] = \
        u_c_p[std::rand() % u_c_p.length()];
    }
    if (force_LC == 1) 
    {
        password[std::rand() % password.length()] = \
        l_c_p[std::rand() % l_c_p.length()];
    }
    std::cout << "The generated password is: " << password << std::endl;
};

std::string Generator::get_password()
{
    return password;
};