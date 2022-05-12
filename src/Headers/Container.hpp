#ifndef POA_L3_CONTAINER_HPP
#define POA_L3_CONTAINER_HPP

#include <string>
#include <list>
#include "Person.hpp"

/**
 * Represent all containable object in project
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Container {
public:
   /**
    * Method to check if a person can leave a container
    * @param personLeaving
    * @return true if can leave or false if not
    */
    Response canLeave(const Person &personLeaving) const;

    /**
     * Method to know if a person can go to a container
     * @param personArriving
     * @return boolean and a message if an error
     */
    virtual Response canArrive(const Person &personArriving) const;

    /**
     * Method to add a person to the container
     * @param personArriving
     * @throw Error if can't be on the container
     */
    void arrive(const Person &personArriving);

    /**
     * Method to remove a person from the container
     * @param personLeaving
     * @throw Error if can't leave the container
     */
    void leave(const Person &personLeaving);

    /**
     * Method to know if a person is in the container
     * @param person
     * @return boolean
     */
    bool isHere(const Person &person) const;

    /**
     * Method to get the name
     * @return name
     */
    std::string getName() const;

    /**
     * Method to get the list of people
     * @return people in the container
     */
    std::list<const Person*> getPeople() const;
protected:
   /**
    * Constructor
    * @param name
    */
   Container(const std::string& name);

   /**
    * Constructor of copy
    * @param name
    * @param people
    */
   Container(const std::string& name, const std::list<const Person*>& people);

   /**
    * Destructor
    */
   virtual ~Container() = default;

private:
   const std::string NAME;
   std::list<const Person*> peopleInContainer;

};

#endif //POA_L3_CONTAINER_HPP
