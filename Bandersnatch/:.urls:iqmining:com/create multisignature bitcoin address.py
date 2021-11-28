#!/usr/bin/python3.10


# Create a multi signature address

from bitcoin import *

# create private keys

create_private_key1 = random_key()
create_private_key2 = random_key()
create_private_key3 = random_key()
create_private_key4 = random_key()
create_private_key5 = random_key()
create_private_key6 = random_key()
create_private_key7 = random_key()
create_private_key8 = random_key()
create_private_key9 = random_key()
create_private_key10 = random_key()
create_private_key11 = random_key()
create_private_key12 =  random_key()
create_private_key13 = random_key()
create_private_key14 = random_key()
create_private_key15 = random_key()
create_private_key16 = random_key()
create_private_key17 = random_key()
create_private_key18 = random_key()
create_private_key19 = random_key()
create_private_key20 = random_key()
create_private_key21 = random_key()
create_private_key22 = random_key()
create_private_key23 = random_key()
create_private_key24 = random_key()



print("Your First Private Key Is: %s" % create_private_key1)
print("Your Second Private Key Is: %s" % create_private_key2)
print("Your Third Private Key Is: %s" % create_private_key3)
print("Your Fourth Private Key Is: %s" % create_private_key4)
print("Your Fifth Private Key Is: %s" % create_private_key5)

print("Your Sixth Private Key Is: %s" % create_private_key6)
print("Your Seventh Private Key Is: %s" % create_private_key7)
print("Your Eight Private Key Is: %s" % create_private_key8)
print("Your Ninth Private Key Is: %s" % create_private_key9)
print("Your Tenth Private Key Is: %s" % create_private_key10)

print("Your Elveneth Private Key Is: %s" % create_private_key11)
print("Your Twelfth Second Private Key Is: %s" % create_private_key12)
print("Your Thirteenth Private Key Is: %s" % create_private_key13)
print("Your Fourteenth Private Key Is: %s" % create_private_key14)
print("Your Fifteenth Private Key Is: %s" % create_private_key15)

print("Your Sixteenth Private Key Is: %s" % create_private_key16)
print("Your Seventeenth Private Key Is: %s" % create_private_key17)
print("Your Eighteenth Private Key Is: %s" % create_private_key18)
print("Your Nineteenth Private Key Is: %s" % create_private_key19)
print("Your Twentieth Private Key Is: %s" % create_private_key20)

print("Your Twenty First Private Key Is: %s" % create_private_key21)
print("Your Twenty Second Private Key Is: %s" % create_private_key22)
print("Your Twenty Third Private Key Is: %s" % create_private_key23)
print("Your Twenty Fourth Private Key Is: %s" % create_private_key24)

create_public_key1 = privtopub(create_putblic_key1)
create_public_key1 = privtopub(create_putblic_key2)
create_public_key1 = privtopub(create_putblic_key3)
create_public_key1 = privtopub(create_putblic_key4)
create_public_key1 = privtopub(create_putblic_key5)
create_public_key1 = privtopub(create_putblic_key6)

create_public_key1 = privtopub(create_putblic_key7)
create_public_key1 = privtopub(create_putblic_key8)
create_public_key1 = privtopub(create_putblic_key9)
create_public_key1 = privtopub(create_putblic_key10)
create_public_key1 = privtopub(create_putblic_key11)
create_public_key1 = privtopub(create_putblic_key12)

create_public_key1 = privtopub(create_putblic_key13)
create_public_key1 = privtopub(create_putblic_key14)
create_public_key1 = privtopub(create_putblic_key15)
create_public_key1 = privtopub(create_putblic_key16)
create_public_key1 = privtopub(create_putblic_key17)
create_public_key1 = privtopub(create_putblic_key18)

create_public_key1 = privtopub(create_putblic_key19)
create_public_key1 = privtopub(create_putblic_key20)
create_public_key1 = privtopub(create_putblic_key21)
create_public_key1 = privtopub(create_putblic_key21)
create_public_key1 = privtopub(create_putblic_key23)
create_public_key1 = privtopub(create_putblic_key24)


print("Your First Public Key Is: %s" % create_public_key1)
print("Your Second Public Key Is: %s" % create_public_key2)
print("Your Third Public Key Is: %s" % create_public_key3)
print("Your Fourth Public Key Is: %s" % create_public_key4)
print("Your Fifth Public Key Is: %s" % create_public_key5)

print("Your Sixth Public Key Is: %s" % create_public_key6)
print("Your Seventh Public Key Is: %s" % create_public_key7)
print("Your Eight Public Key Is: %s" % create_public_key8)
print("Your Ninth Public Key Is: %s" % create_public_key9)
print("Your Tenth Public Key Is: %s" % create_public_key10)

print("Your Elveneth Public Key Is: %s" % create_public_key11)
print("Your Twelfth Second Public Key Is: %s" % create_public_key12)
print("Your Thirteenth Public Key Is: %s" % create_public_key13)
print("Your Fourteenth Public Key Is: %s" % create_public_key14)
print("Your Fifteenth Public Key Is: %s" % create_public_key15)

print("Your Sixteenth Public Key Is: %s" % create_public_key16)
print("Your Seventeenth Public Key Is: %s" % create_public_key17)
print("Your Eighteenth Public Key Is: %s" % create_public_key18)
print("Your Nineteenth Public Key Is: %s" % create_public_key19)
print("Your Twentieth Public Key Is: %s" % create_public_key20)

print("Your Twenty First Public Key Is: %s" % create_public_key21)
print("Your Twenty Second Public Key Is: %s" % create_ublic_key22)
print("Your Twenty Third Public Key Is: %s" % create_public_key23)
print("Your Twenty Fourth Public Key Is: %s" % create_ublic_key24)

print('\n')


create_multi_signature = mk_multisig_script(create_private_key$)
create_multi_signature_address = scriptaddr(create_multi_signature)
print("Your Multi Signature address is: %s" % create_multi_signature_address)

















