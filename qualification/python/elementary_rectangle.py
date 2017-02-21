class Mushroom:
	def __init__(self, x, y):
		Mushroom.x = x
		Mushroom.y = y
		Mushroom.closest_mush = None

def distance2(mush1, mush2):
	return (mush2.x - mush1.x)**2 + (mush2.y - mush1.y)**2

if __name__ == "__main__":
	pizza = [['m', 't', 't', 'm', 't', 't'], ['t', 'm', 't', 't', 'm', 't'], ['t', 't', 'm', 't', 'm', 't'], ['m', 't', 't', 'm', 't', 't']]
	mush = []

	for line in range(0, 2, 1):
		for row in range(0, 4, 1):
			if pizza[row][line] is 'm':
				mush.append(Mushroom(line, row))

	mush2 = list(mush)
	least_distance = 100000
	for mushroom in mush:
		for mushroom_2 in mush:
			if (distance2(mushroom, mushroom_2) < least_distance) and (distance2(mushroom, mushroom_2) != 0):
				least_distance = distance2(mushroom, mushroom_2)
				mushroom.closest_mush = mushroom_2
				mushroom_2.closest_mush = mushroom
		del mush[mush.index[mushroom_2]]
		del mush[mush.index[mushroom]]

	for mushroom in mush2:
		print mushroom.x + " " + mushroom.y