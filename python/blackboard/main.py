
class Bike():

    def __init__ (self, name, tyresize):
        self.name = name
        self.tyresize = tyresize

class MTB(Bike):

    def __init__ (self, name, tyresize, travel):
        super().__init__(name, tyresize)
        self.travel = travel


roadbike = Bike('trek', 28)
yeti = MTB('yeti', 26, 150)

print( yeti.travel )



    

