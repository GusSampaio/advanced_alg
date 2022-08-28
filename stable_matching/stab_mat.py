class Woman:
	def __init__(self, informations, n_preferences):
		self.name = informations[0]
		self.engaged = False
		self.partner = 0
		self.w_pref = []
		for i in range(n_preferences):
			self.woman_preference.append(informations[i+1])

class Man:
	def __init__(self, informations, n_preferences):
		self.name = informations[0]
		self.m_pref = []
		self.engaged = False
		self.partner = 0
		for i in range(n_preferences):
			self.man_preference.append(informations[i+1])

def to_engage(woman, man):
	woman.engaged = True
	man.engaged = True
	woman.partner = man
	man.partner = woman

def stableMarriage(men_list, women_list, n_mariages):

	freeCount = n_mariages

	# While there are free men
	while (freeCount > 0):
		
		# Pick the first free man
		m = 0
		while (m < n_mariages):
			if (men_list[m].engaged == False):
				break
			m += 1

		# One by one go to all women according to m's preferences. 
		i = 0
		while i < n_mariages and men_list[m].engaged == False:
			w = men_list[m].m_pref[i]

			for i in range(n_mariages):
				if w == women_list[i].name:
					w = women_list[i]
					break

			# The woman of preference is free, w and m become partners.
			# So we can say they are engaged not married
			if (w.engaged ==  False):
				to_engage(w, men_list[m])
				

			# If w is not free
			# Find current engagement of w
			else:
				m1 = wPartner[w - n_mariages]

				# If w prefers m over her current engagement m1,
				# then break the engagement between w and m1 and
				# engage m with w.
				if (wPrefersM1OverM(prefer, w, m, m1, n_mariages) == False):
					wPartner[w - n_mariages] = m
					mFree[m] = True
					mFree[m1] = False
			i += 1

			# End of Else
		# End of the for loop that goes
		# to all women in m's list
	# End of main while loop

	# Print solution
	for i in range(n_mariages):
		print(i+1, "\t", wPartner[i])

if __name__ == '__main__':

	test_cases = int(input())
	
	#remake test cases
	for i in range(test_cases):
		# Number of Men or Women
		n_mariages = int(input())
	
		#readed string 
		prefer = []

		women_list = []
		men_list = []
		
		#received string changed into 'int' numbers
		prefers = []

		for i in range(n_mariages):
			prefer = input()
			new_prefer = prefer.split()
			new_prefer = [int(i) for i in new_prefer]
			women_list.append(Woman(new_prefer, n_mariages))

		for i in range(n_mariages):
			prefer = input()
			new_prefer = prefer.split()
			new_prefer = [int(i) for i in new_prefer]
			men_list.append(Man(new_prefer, n_mariages))

		stableMarriage(men_list, women_list, n_mariages)