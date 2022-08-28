#student: Gustavo Sampaio
#id: 122623992
class Woman:
	def __init__(self, informations, n_preferences):
		self.name = informations[0]
		self.engaged = False
		self.partner = -1
		self.w_pref = []
		for i in range(n_preferences):
			self.w_pref.append(informations[i+1])

class Man:
	def __init__(self, informations, n_preferences):
		self.name = informations[0]
		self.engaged = False
		self.partner = -1
		self.m_pref = []
		for i in range(n_preferences):
			self.m_pref.append(informations[i+1])

def to_engage(woman, man):
	woman.engaged = True
	man.engaged = True
	woman.partner = man.name
	man.partner = woman.name

def w_prefers_m1_Over_m(w, m, groom, n_mariages):
	for i in range(n_mariages):
		if w.w_pref[i] == groom.name:
			return True
		if w.w_pref[i] == m.name:
		    return False

def stableMarriage(men_list, women_list, n_mariages):

	freeCount = n_mariages

	# While there are free men
	while (freeCount > 0):
		
		# Pick the first free man
		m = 0
		actual_man = 0
		while (m < n_mariages):
			if (men_list[m].engaged == False):
				actual_man = men_list[m]
				break
			m += 1
		
		if actual_man == 0:
			break

		# One by one go to all women according to m's preferences. 
		i = 0
		while i < n_mariages and actual_man.engaged == False:
			woman = actual_man.m_pref[i]

			for j in range(n_mariages):
				if woman == women_list[j].name:
					woman = women_list[j]
					break

			# The woman of preference is free, w and m become partners.
			# So we can say they are engaged not married
			if (woman.engaged ==  False):
				to_engage(woman, actual_man)
				freeCount -= 1
				

			# If w is not free
			# Find current engagement of w
			else:
				for j in range(n_mariages):
					if woman.partner == men_list[j].name:
						groom = men_list[j]
						break

				# If w prefers m over her current engagement m1,
				# then break the engagement between w and m1 and
				# engage m with w.
				if (w_prefers_m1_Over_m(woman, actual_man, groom, n_mariages) == False):
					actual_man.engaged = True
					actual_man.partner = woman.name
					woman.partner = actual_man.name
					groom.engaged = False
					groom.partner = -1

			i += 1

			# End of Else
		# End of the for loop that goes
		# to all women in m's list
	# End of main while loop

	# Print solution
	for i in range(n_mariages):
		print(men_list[i].name, ' ', men_list[i].partner)

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