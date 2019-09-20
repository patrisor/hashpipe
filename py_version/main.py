# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 11:44:18 by patrisor          #+#    #+#              #
#    Updated: 2019/09/20 13:40:31 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os
import hashlib

def die(reason):
    print(reason + "\n")
    return -1

def print_usage():
    return ("usage: python3 main.py [hash] [hash_file]\n\nHASHES:\n\t- sha256\n\t- sha512\n")

def readFile(fileName):
    return [line.rstrip('\n') for line in open(fileName)]

def pullHashes(arg1, arg2, ret = {}):
    lines = readFile(arg2)[0].split('login')[1:]
    for r in lines:
        hit = 0
        user = password = ''
        for j in r:
            if hit == 3: break
            if hit == 2: user += j
            if j == '"': hit += 1
        user = user[:-1]
        for i in range(7, 71, 1):
            password += r[(r.find(";s:64:" if arg1 == "sha256" else ";s:128:")) + i]
        ret.__setitem__(user, password)
    return ret

def bruteForce(arg1, arg2, ret = {}):
    for key, value in pullHashes(arg1, arg2).items():
        for line in readFile(os.environ['PWD'] + '/includes/passwords.txt'):
            hashed = (hashlib.sha256(line.encode('utf-8')).hexdigest() if arg1 == "sha256" else
                    hashlib.sha512(line.encode('utf-8')).hexdigest())
            print(hashed + " -> " + line)
            if value == hashed: ret.__setitem__(key, line)
    return ret

def main():
    if (len(sys.argv) <= 2 or len(sys.argv) > 3):
        return (die(print_usage()))
    for key, value in bruteForce(sys.argv[1], sys.argv[2]).items():
        print("\nPassword(s) cracked!:\n " + "Username: " + key + ", Password: " + value + "\n")

if __name__ == "__main__":
    main()
