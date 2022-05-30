class ParkingSystem {
    
    private int bigSize,mediumSize,smallSize;
    
    public ParkingSystem(int big, int medium, int small) {
        bigSize=big;
        mediumSize=medium;
        smallSize=small;
    }
    
    public boolean addCar(int carType) {
        if(carType==1 && bigSize>0)
        {
            bigSize--;
            return true;
        }
        else if(carType==2 && mediumSize>0)
        {
            mediumSize--;
            return true;
        }
        else if(carType==3 && smallSize>0)
        {
            smallSize--;
            return true;
        }
        return false;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */