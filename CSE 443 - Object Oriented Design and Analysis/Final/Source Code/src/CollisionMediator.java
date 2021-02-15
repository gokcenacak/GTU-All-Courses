import java.util.Random;

/**
 * This class represents a mediator for human collisions in a population which is in a epidemic.
 * @author Gokce Nur Erer
 */
public class CollisionMediator {
    private EpidemicSimulator simulator;

    /**
     * Constructor which creates a collision mediator with a given simulator.
     * @param simulator Simulator which mediator will work on.
     */
    public CollisionMediator(EpidemicSimulator simulator){
        this.simulator = simulator;
    }

    /**
     * Checks collisions in a given simulator
     */
    public void checkCollisions(){
        java.util.List<Human> humans = simulator.getPopulation().getHumans();
        int populationSize = humans.size();
        for(int i = 0; i < populationSize; i++){
            for(int j = 0; j < populationSize; j++){
                if(i != j){
                    if(humans.get(i).canMove() && humans.get(j).canMove()){
                        if(humans.get(i).getXPos() == humans.get(j).getXPos() &&
                                humans.get(i).getYPos() == humans.get(j).getYPos()) {
                            handleCollision(humans.get(i),humans.get(j));

                        }
                    }

                }
            }
        }
    }

    /**
     * Handles collision of two human
     * @param human1 First human
     * @param human2 Second human
     */
    public void handleCollision(Human human1, Human human2){
        int socialTime = Math.max(human1.getSocialTime(), human2.getSocialTime());
        human1.stall(socialTime);
        human2.stall(socialTime);
        if(human1.isInfected() && !human2.isInfected() || !human1.isInfected() && human2.isInfected()){
            Human healthyHuman = !human1.isInfected() ? human1 : human2;

            double socialDistance = Math.min(human1.getSocialDistance(), human2.getSocialDistance());
            double spreadingFactor = simulator.getSpreadingFactor();
            double probabilityOfInfection = spreadingFactor * (1 + (double)socialTime / 10) * human1.getWearsMask() * human1.getWearsMask() * (1 - socialDistance / 10);
            probabilityOfInfection = Math.min(probabilityOfInfection,1.0);
            if(probabilityOfInfection == 1.0){
                healthyHuman.setInfected();
                int secondsToKill = (int) (100 * (1 - simulator.getConstantMortalityRate()));
                healthyHuman.startCountdownAfterInfection(25, secondsToKill);
                simulator.increaseInfectedCount();
            }
            else{
                Random rand = new Random();
                int chanceOfInfection = rand.nextInt(100) + 1;
                if(chanceOfInfection <= probabilityOfInfection * 100){
                    healthyHuman.setInfected();
                    int secondsToKill = (int) (100 * (1 - simulator.getConstantMortalityRate()));
                    healthyHuman.startCountdownAfterInfection(25, secondsToKill);
                    simulator.increaseInfectedCount();
                }
            }

        }

    }


}
