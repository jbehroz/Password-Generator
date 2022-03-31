#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

/*
This class generates a password after user input, then prints that password into
the console after the user is satisfied. The constructor handles all I/O so 
there is no need to call any of the other functions unless you want to access
the password again as an output instead of a print statement.
*/
class Generator {
    public:
    /* 
    asks the user if they want the default password settings, if not they can 
    choose individual settings to change or leave on default before the password
    is generated and outputted.
    */
    Generator();
    // uppercase and lowercase character pools
    std::string u_c_p;
    std::string l_c_p;
    // special character pool
    std::string s_c_p;
    //numbers as characters pool
    std::string n_p;
    // outputs the password
    std::string get_password();
    
    private:
    // the password string that will output after user input
    std::string password;
    // key to generate random chars from, default random int 
    // int rng_key;
    // length of password, default 12
    int p_length; 
    // pool of characters to draw from per character; explained below
    std::string pool; 
    /*
    These booleans decide what characters will be in the password pool.
    By default, the special_chars, and nums are set to 1
    for true and a_u aka all uppercase and a_l aka all lowercase are set to 0
    for false. User input in the constructor can change any of these booleans, 
    therefore changing the pool and then the password generated. The default 
    values will lead to a password of length 12 with each character being a 
    random character from a pool of special characters, numbers, and all 
    lowercase and uppercase english characters. It is possible to have a 
    password made of only numbers, for example, if all booleans but nums is set 
    to 0 and nums is set to 1.
    */
    bool special_chars;
    bool nums;
    bool a_u;
    bool a_l;
    /* 
    these booleans force the password to have at least one of the characters
    from the pool in the password, just in case it randomly has 0 of that type
    */
    bool force_SC;
    bool force_NC;
    bool force_UC;
    bool force_LC;
};

#endif