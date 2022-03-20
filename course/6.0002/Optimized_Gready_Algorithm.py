import random


class Food(object):
    def __init__(self, n, v, m):
        self.name = n
        self.value = v
        self.calories = m

    def getValue(self):
        return self.value

    def getCost(self):
        return self.calories

    def density(self):
        return self.getValue() / self.getCost()

    def __str__(self):
        return self.name + ": <" + str(self.value) + ", " + str(self.calories) + ">"


def buildMenu(names, values, calories):
    menu = []
    for i in range(len(values)):
        menu.append(Food(names[i], values[i], calories[i]))
    return menu


def buildLargeMenu(numItems, maxVal, maxCost):
    items = []
    for i in range(numItems):
        items.append(
            Food(str(i), random.randint(1, maxVal), random.randint(1, maxCost))
        )
    return items


def maxVal(toConsider, avail):
    """Assumes toConsider a list of items, avail a weight
    Resturns a tuple of the total value of a solution to
    0/1 knapsack problem and the items of that solution"""
    if toConsider == [] or avail == 0:
        result = (0, ())
    elif toConsider[0].getCost() > avail:
        # explore right branch only
        result = maxVal(toConsider[1:], avail)
    else:
        nextItem = toConsider[0]
        # explore left branch
        withVal, withToTake = maxVal(toConsider[1:], avail - nextItem.getCost())
        withVal += nextItem.getValue()
        # explore right branch
        withoutVal, withoutToTake = maxVal(toConsider[1:], avail)
        # choose better branch
        if withVal > withoutVal:
            result = (withVal, withToTake + (nextItem,))
        else:
            result = (withoutVal, withoutToTake)

    return result


def testMaxVal(foods, maxUnits, printItem=True):
    print("Use search tree to allocate", maxUnits, "calories")
    val, taken = maxVal(foods, maxUnits)
    print("Total value of items taken = ", val)
    if printItem:
        for item in taken:
            print("    ", item)


names = ["wine", "beer", "pizza", "burger", "fries", "cola", "apple", "donut", "cake"]

values = [89, 90, 95, 100, 90, 79, 50, 10]
calories = [123, 154, 258, 354, 365, 150, 95, 195]

for numItems in range(5, 61, 5):
    print("Try a menu with", numItems, "items")
    items = buildLargeMenu(numItems, 90, 250)
    testMaxVal(items, 1000, False)
