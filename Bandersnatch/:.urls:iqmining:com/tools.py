pip install bitcoin

from bitcoin import *

generate_private_key = random_key()
print(" your Private Key is: %s\n" % generate_private_key)

# generate public key

generate_public_key = privtopub(generate_public_key)
print("your Public Key is: %s\n" generate_public_key)

# create a bitcoin address

create_a_bitcoin_address = pubtoaddr(my_public_key)
print("your Bitcoin Address is: %s\n" % create_a_bitcoin_address)

