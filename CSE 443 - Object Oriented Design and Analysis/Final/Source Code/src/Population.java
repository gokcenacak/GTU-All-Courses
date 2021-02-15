import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * This class represents a population
 * @author Gokce Nur Erer
 */
public class Population {
    private List<Human> humans;

    /**
     * Constructor which creates a population
     */
    public Population(){
        humans = new ArrayList<>();
    }

    /**
     * Returns humans in the population
     * @return Humans in the population
     */
    public List<Human> getHumans() {
        return humans;
    }

    /**
     * Adds a single human to the population
     * @param human Human to be added to the population
     */
    public void addHuman(Human human){
        humans.add(human);
    }

    /**
     * Adds a group of humans to the population
     * @param humanGroup Human group to be added to the population
     */
    public void addHumanGroup(List<Human> humanGroup){
        humans.addAll(humanGroup);
    }

    /**
     * Removes a human from the population
     * @param human Human to be removed from the population
     */
    public void removeHuman(Human human){
        humans.remove(human);
    }

    /**
     * Infects a random person in the population
     * @return Human who is infected
     */
    public Human infectRandomHuman(){
        Random rand = new Random();
        int humanToInfect = rand.nextInt(humans.size());
        humans.get(humanToInfect).setInfected();
        return humans.get(humanToInfect);
    }

    /**
     * Returns the mask usage percentage in the population
     * @return Mask usage percentage in the population
     */
    public double getMaskUsagePercentage(){
        double maskUserCount = 0;
        for(Human human : humans){
            if(human.getWearsMask() == 0.2)
                maskUserCount++;
        }

        return maskUserCount/humans.size();
    }

    /**
     * Returns the average social distance in the population
     * @return Average social distance in the population
     */
    public double getAvgSocialDistance(){
        double socialDistanceTotal = 0;
        for(Human human : humans){
            socialDistanceTotal+= human.getSocialDistance();
        }

        return socialDistanceTotal/humans.size();
    }

    /**
     * Returns the healthy count in the population at that moment
     * @return Healthy count
     */
    public int getHealthyCount(){
        int count = 0;
        for(Human human : humans){
            if(human.isHealthy()){
                count++;
            }
        }
        return count;
    }

    /**
     * Returns the hospitalized count in the population at that moment
     * @return Hospitalized count
     */
    public int getHospitalizedCount(){
        int count = 0;
        for(Human human : humans){
            if(human.isHospitalized()){
                count++;
            }
        }
        return count;
    }

    /**
     * Returns the infected count in the population at that moment
     * @return Infected count
     */
    public int getInfectedCount(){
        int count = 0;
        for(Human human : humans){
            if(human.isInfected()){
                count++;
            }
        }
        return count;
    }

}
