class Fieldelement(object):
	"""docstring for FieldElement"""
	def __init__(self, num ,prime):
		if num >= prime or num < 0:
			error = 'Num {} not in field range 0 to {}'.format(num, prime - 1)
			raise ValueError(error)
		self.num = num
		self.prime = prime

		def __repr__(self):
			return 'Fieldelement_{}({})'.format(self.prime, self.num)

		def __eq__(self, other):
			if other is None:
				return False
			return self.num == other.num and self.prime == other.prime

		def __ne__(self, other):
			return not (self == other)

		def __sub__(self, other):
			if self.prime != other.prime:
				raise TypeError('Cannot subtract two numbers in different fields')
				# self.num and other.num are the actual value
				# self.prime is what we need to mod against
				num = (self.num - other.num) % self.prime
				# we return an element of the same class
				return self.__class__(num, self.prime)


		def __mul__(self, other):
			if self.prime != other.prime:
				raise TypeError('Cannot multiply two numbers in different fields')
				# self.num and other.num are the actual values
				# self.prime is waht we need to mod against
			num = (self.num * other.num) % self.prime
				# we return an element of the same class
			return self.__class__(num, self.prime)

		def __truediv__(self, other):
			if self.prime != other.prime:
				raise TypeError('Cannot divide two numbers in different fields')
				# use fermat's little theorem:
				# self.num**(p-1) % p == 1
				# this means:
				# 1/n == pow(n, p-2, p)
				# we return an element of the same class

				num = self.num * pow(other.num, self.prime - 2, self.prime) % self.prime
				return self.__class__(num, self.prime)


prime = 57
print((44+33)%prime)
print((9-29)%prime)
print((17+42+49)%prime)
print((52-30-38)%prime)




prime = 97
print(95*45*31 % prime)
print(17*13*19*44 % prime)
print(12**7*77**49 % prime)



# when not using the function sorted the results will always return volatility instead of any mathematical results

prime = 19
for k in (1, 3, 7, 13, 18):
	print([k*i % prime for i in range(prime)])


# when using the function sorted the result are always constant

for k in (1, 3, 7, 13, 18):
	print(sorted([k*i % prime for i in range(prime)]))



"""
for p = 7, 11, 17, 31, what is this set in Fsub p?


{1^(p-1),2^(p-1),3^(p-1),4^(p-1), ...(p-1)^(p-1)}
"""



for prime in (7, 11, 17, 31):
	print([pow(i, prime-1, prime) for i in range(1, prime)])



prime = 31
print(3*pow(24, prime-2, prime) % prime)
print(pow(17, prime-4, prime))
print(pow(4, prime-5, prime)*11 % prime)



