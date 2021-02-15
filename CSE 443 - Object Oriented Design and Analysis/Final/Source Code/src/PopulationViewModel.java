import java.util.ArrayList;
import java.util.List;

/**
 * This class represents a population's view model
 * @author Gokce Nur Erer
 */
public class PopulationViewModel {
    private List<HumanViewModel> humanViewModels;
    private Population population;

    /**
     * Constructor that creates the population view model with a given population
     * @param population Population whose view model will be created
     */
    public PopulationViewModel(Population population){
        this.population = population;
        humanViewModels = new ArrayList<>();
        for(Human human : population.getHumans()){
            humanViewModels.add(new HumanViewModel(human));
        }
    }

    /**
     * Returns the human view models in the population view model
     * @return Human views in the population view
     */
    public List<HumanViewModel> getHumanViewModels() {
        return humanViewModels;
    }

    /**
     * Returns a human view model with a given human in the population view model
     * @param human Human whose view model is requested
     * @return Human view model with the requested human, null if human view model doesn't exists in population view model
     */
    public HumanViewModel getWithHuman(Human human){
        for(HumanViewModel hvm : humanViewModels){
            if(hvm.getHuman().equals(human)){
                return hvm;
            }
        }
        return null;
    }

    /**
     * Updates the population which is represented with this view model
     * @param population Population to be used in updating
     */
    public void updatePopulation(Population population){
        this.population = population;
        humanViewModels.clear();
        for(Human human : population.getHumans()){
            humanViewModels.add(new HumanViewModel(human));
        }
    }

}
