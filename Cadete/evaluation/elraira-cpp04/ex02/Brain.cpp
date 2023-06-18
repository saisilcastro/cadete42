/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:17:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 23:34:18 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::string randomIdeas[100] = {
         "Did they seriously expect me to chase my tail? I'm not falling for that again.",
        "If I stare at the food long enough, maybe it will magically jump into my bowl.",
        "I wonder if they realize that the vacuum cleaner is my mortal enemy.",
        "Who needs thumbs when you have paws? Life is better this way.",
        "I bet I could catch that squirrel if I just had a jetpack.",
        "Why do they keep throwing the stick? Can't they see I'm perfectly content lying here?",
        "I should start a nap club. Membership would be purrfectly exclusive.",
        "Humans think they're so smart with their opposable thumbs. I'll show them who's boss.",
        "What's the deal with the red dot? It's like an elusive mini sunbeam.",
        "If I pretend to be invisible, maybe they won't make me take a bath.",
        "I have mastered the art of the 'puppy eyes.' It's my secret weapon for getting treats.",
        "That spot on the carpet has been bothering me. Time to dig a hole and bury it.",
        "I heard humans talk about 'working out.' I do that every day when I chase my tail.",
        "The cat next door thinks it's so clever, but I've mastered the art of door-opening.",
        "I can fit into this box. Therefore, I must sit in this box. It's the law of physics.",
        "Why does the human always scream when I bring them a 'gift'? I thought they'd be grateful.",
        "There's a whole world out there beyond the backyard fence. I must explore it all.",
        "If I knock this glass off the table, will it make a sound? Time to conduct an experiment.",
        "Humans say 'bath time' with such enthusiasm. I'm starting to think it's not a good thing.",
        "I'm convinced the birds are taunting me with their ability to fly. Someday, I'll catch one.",
        "I'm not fat; I'm just fluffy. It's called 'big-boned' in the animal kingdom.",
        "I've been practicing my meow all night. I hope they finally understand what I'm saying.",
        "Who needs an alarm clock when I can wake the whole house with my barking?",
        "If I hide my bone in the couch, it becomes a surprise for future me. It's like time travel.",
        "Belly rubs should be a human's full-time job. They are essential for my happiness.",
        "The human thinks they're the boss, but we all know I'm the one running this household.",
        "If I close my eyes, maybe they won't notice that I stole their sandwich.",
        "I need to investigate why the toilet water disappears when I flush. It's pure sorcery.",
        "I'll never understand why the human freaks out when I bring in a little mud. It's called fashion.",
        "If I jump high enough, maybe I'll reach that delicious-looking pizza on the kitchen counter.",
        "The humans have a secret stash of treats somewhere, and I will find it.",
        "Who needs a pet bed when the human's lap is so cozy? It's the ultimate sleeping spot.",
        "I'm convinced the vacuum cleaner is a shape-shifting monster. I must protect my family.",
        "I've been practicing my 'puppy eyes' in front of the mirror. They're reaching superhero levels.",
        "The human always says, 'Who's a good boy?' as if they don't already know the answer.",
        "Why do they call it 'fetch'? I'm the one doing all the work while they stand there.",
        "If I pretend to be asleep, maybe the human won't notice I stole their spot on the couch.",
        "I've hidden my favorite toy somewhere in the house. It's like a treasure hunt for the humans.",
        "Why does the human always scream when I lick their face? Don't they appreciate my kisses?",
        "I'm convinced the mailman is an evil mastermind. I must alert the authorities.",
        "The human spends hours staring at that glowing rectangle. It must be a window to another world.",
        "I've mastered the art of stealth. No treat is safe from my ninja skills.",
        "If I make sad eyes long enough, maybe they'll give in and share their ice cream.",
        "The world would be a better place if everyone just had a belly rub break.",
        "I've discovered the perfect hiding spot. The human will never find me under this blanket.",
        "If I bat at the shiny object, maybe it will finally give me the attention I deserve.",
        "They say curiosity killed the cat, but satisfaction brought it back. It's a risk worth taking.",
        "If I tilt my head just right, it confuses the human and they give me extra treats.",
        "I've observed the humans' strange ritual of 'dancing.' It's like they're having seizures.",
        "If I hide in this box, maybe they won't notice I'm not a cat. I can be stealthy too.",
        "I'm convinced the squirrels are plotting against me. I must stay vigilant.",
        "Why do they keep calling me a 'good boy'? Clearly, I'm the greatest boy in the world.",
        "I've been practicing my dance moves in secret. My talent will be revealed at the next party.",
        "If I stare at the treat bag long enough, maybe it will open by telekinesis.",
        "The humans have an unhealthy obsession with throwing things away. I must investigate.",
        "I've mastered the art of begging. It's all in the eyes and the subtle paw placement.",
        "Why do they get so excited about 'walkies'? Can't they see I'm content with my comfy bed?",
        "I'm convinced the doorbell is a call to battle. I must defend the house from intruders.",
        "If I roll on my back, maybe the human will give me a tummy rub. It's worth a try.",
        "The humans always leave these round objects lying around. Perfect for a game of soccer.",
        "I've perfected the art of balancing treats on my nose. It's my signature party trick.",
        "Why do they put clothes on me? I'm not a fashion model; I'm a pet superstar.",
        "I've observed the humans' fascination with screens. It's like they're hypnotized by them.",
        "If I sit on the keyboard, maybe the human will realize I'm the one in charge here.",
        "I'm convinced the dog in the mirror is plotting against me. I must show it who's the alpha.",
        "Why do they get so upset when I chase my own tail? It's the ultimate form of entertainment.",
        "I've discovered the art of parkour. Watch me bounce off the walls with grace.",
        "Why do humans insist on hiding treats from me? Don't they know sharing is caring?",
        "If I sit on their newspaper, they'll have no choice but to give me attention.",
        "The human talks about 'diet' like it's a good thing. I'm proud of my fluffy figure.",
        "I've observed the humans' strange habit of talking to themselves. They must have secret powers.",
        "If I hide behind the couch, maybe they won't notice I'm not a cat. Stealth level: expert.",
        "I'm convinced the red dot is a government conspiracy. Time to expose the truth.",
        "I've discovered the art of camouflage. Watch as I blend in perfectly with the carpet.",
        "If I sit on the laptop, maybe the human will realize I need more attention.",
        "I'm convinced the fridge is a secret portal to a world of endless treats. Must investigate.",
        "Why do humans take pictures of me when I'm trying to sleep? I'm not a model, you know.",
        "I've perfected my 'puppy eyes' technique. Resistance is futile.",
        "The cat thinks it's so clever, but I can open doors. Who's the genius now?",
        "I've been working on my bark pitch. Soon, I'll have my own chart-topping single.",
        "I'm convinced that the spot behind the fridge is a portal to another dimension. Must explore.",
        "The humans keep trying to teach me tricks. Little do they know, I'm the one training them.",
        "I can't understand why they don't appreciate my artistic talent of rearranging the trash.",
        "I've decoded the secret language of the birds. They're planning a takeover.",
        "If I knock everything off the table, it's just me helping with their spring cleaning.",
        "I'm on a mission to catch my tail. It's the ultimate enemy that must be defeated.",
        "Why do they keep calling me a 'good boy'? Clearly, I'm the greatest boy in the world.",
        "I've been practicing my howling skills. Soon, the whole neighborhood will sing along.",
        "If I hide under the blanket, maybe they won't see me and try to take me to the vet.",
        "Why do they insist on cutting my nails? They're essential for my epic scratching abilities.",
        "I've been practicing my singing skills. I'm convinced I'm the next howling sensation.",
        "If I sit on the laptop, maybe the human will realize I need more attention.",
        "I'm convinced the squirrels are plotting against me. I must stay vigilant.",
        "Why do they insist on hiding treats from me? Don't they know sharing is caring?",
        "If I sit on their newspaper, they'll have no choice but to give me attention.",
        "The human talks about 'diet' like it's a good thing. I'm proud of my fluffy figure.",
        "I've observed the humans' strange habit of talking to themselves. They must have secret powers.",
        "If I hide behind the couch, maybe they won't notice I'm not a cat. Stealth level: expert.",
        "I'm convinced the red dot is a government conspiracy. Time to expose the truth.",
        "I've discovered the art of camouflage. Watch as I blend in perfectly with the carpet."
    };

    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = randomIdeas[i];
    }
    std::cout << WHITE << "New Brain created!" << RESET << std::endl;
}

Brain::Brain(Brain const& src) {
    std::cout << WHITE << "Brain created by copy!" << RESET << std::endl;
    *this = src;
}

Brain::~Brain() {
    std::cout << RED << "Brain destroyed!" << RESET << std::endl;
}

Brain& Brain::operator=(Brain const& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = rhs._ideas[i];
        }
    }
    return *this;
}

void Brain::getIdeas(int index) const {
    if(index >= 0 && index < 100) {
        std::cout << this->_ideas[index] << std::endl;
    } else {
        std::cout << RED << "Invalid index" << std::endl;
        return;
    }
}
