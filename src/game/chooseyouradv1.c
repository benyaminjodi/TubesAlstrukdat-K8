#include "boolean.h"
#include <stdio.h>

#define Nil NULL

#include<stdio.h>
 
typedef struct node {
    char* data;
    struct node* left;
    struct node* right;
} node;

boolean isLeaf(node base) {
    if ((base.left == Nil) && (base.right == Nil)){
        return(true);
    }
    else{
        return(false);
    }

}

int result=0;

int recursive(node* base){
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("%s", (*base).data);
    if (isLeaf(*base)==true)
    {
        return 0;
    }
    else
    {
        int answer;
        boolean isValid;
        isValid = false;
        //Inputting answwer from user
        while (isValid!=true)
        {
            printf("Type whether you choose yes or no (0 for yes/1 for no)\n");
            scanf("%d", &answer);
            if (answer==0)
            {
                isValid=true;
            }
            if (answer==1)
            {
                isValid=true;
            }
        }
        //Decision branching
        if (answer==0)
        {
            result=recursive((*base).left)+1;
            return (result);
        }
        if (answer==1)
        {
            result=recursive((*base).right)+1;
            return (result);
        }
    }
}

void playchooseyouradv(){
    //-----------------------------------------------------------------//
    int scoreCount=0;
    node route1, route2, route3, route4, route5, route6, route7, route8, route9, route10, route20, route30, route40, route50, route70;
    //Inserting NIL to leafs
    route10.left=Nil;
    route10.right=Nil;
    route20.left=Nil;
    route20.right=Nil;
    route30.left=Nil;
    route30.right=Nil;
    route40.left=Nil;
    route40.right=Nil;
    route50.left=Nil;
    route50.right=Nil;
    route70.left=Nil;
    route70.right=Nil;
    route9.left=Nil;
    route9.right=Nil;
    //Inserting child address to nodes
    route1.left=&route2;
    route1.right=&route10;
    route2.left=&route20;
    route2.right=&route3;
    route3.left=&route30;
    route3.right=&route4;
    route4.left=&route40;
    route4.right=&route5;
    route5.left=&route50;
    route5.right=&route6;
    route6.left=&route7;
    route6.right=&route7;
    route7.left=&route70;
    route7.right=&route8;
    route8.left=&route9;
    route8.right=&route9;
    route9.left=Nil;
    route9.right=Nil;
    //Text contained here//
    route1.data="\nYou find yourself standing in a beautiful garden. It teems with all the birds of the air, and all of the creatures of the Earth, and every good thing that grows.\nAs you explore, you feel an incredible sense of peace and rightness, as if the garden had been created just for you.\nThis is the place you belong. Still, you are restless and lonely. You begin to explore your surroundings.\nAt the western edge of the garden, there is a gate. \n\nDo you walk through?\n\n";
    route10.data="\nYou wish to see more of the garden before you leave its bounds.\nSoon, you are glad you have chosen as you did, for you find the perfect companion for all your days and nights.\nYou come to believe you have found a new Eden, as well.\nIt seems impossible for a place so perfect to be other than Paradise.\nWhen they are born, you name your children Kane and Abelle.\n\n";
    route2.data="\nGates, like books, are meant to be opened, and you would never be truly content if you did not know what lay on the other side.\nYou pass through the gate and enter into a dark forest.\nYou hesitate for a moment, look back, but the forest stretches behind you as if the garden had never been.\n\nYou continue on.\n\nShadows deepen. An owl calls. Something cries out at a distance and is silenced.\nYou grow chilled, and your feet develop a talent for finding uneven spots of ground, tree roots, and rocks.\nAfter the third time you fall, you lean against the very tree whose roots last tangled your feet.\nThe bark prickles and rubs against your back, but it is a welcome distraction from your bruised knees and skinned palms.\nYour bones are weary and your muscles ache.\nYou crave sleep. A brief rest to fortify yourself for your journey. \n\nDo you close your eyes?\n\n";
    route20.data="\nYou close your eyes, and drift into sleep. When you awaken, you are in your own bed.\nThe previous events were a dream, which has already begun to fade.\nYou spend the rest of your life trying to return to the winding path in the dark forest.\n\nYou never will.\n\n";
    route3.data="\nYou scrub your hands across your eyes and push yourself back to your feet.\nThe path takes you on a short, downhill curve, and winds around to the door of an inn.\nThe Quill and Ink, reads the sign over the door. You smile, and enter.\nInside, there is warmth, the hearty scent of food, and a group of people singing songs both off-key and bawdy.\nYou slide seamlessly into the small community, and feel refreshed after you have shared a meal and stood a round of drinks.\nEventually, you notice the singing has died down, replaced by a rapt silence. \nThere is a knot of people wound tight around the fire, telling stories.\nAt first, you simply listen, but then you are asked to tell a tale of your own.\nIt is the tale, not the coin, that will pay your shelter for the night.\n\nDo you tell a story?\n\n";
    route30.data="\nYou are warm and happy, and just drunk enough to think that telling a story is something you can do.\nYou invoke the muse, and she speaks through you.\nWhen you finish, only the crackling of the fire breaks the silence.\nYou watch as, next to you, a single tear trickles down a perfect cheek.\n\nIt is the last story you will ever tell.\n\n";
    route4.data="\nThe only story you know is your own, you say, and you must continue on to know how it ends.\nYou make your excuses, and stand one more round before you leave to ensure there will be no hurt feelings. \nAnd, more importantly, no knives in the back as you walk through the door.\nThe air is crisp, and you are refreshed. \nThe moon limns the trees in silver, and makes clear your path.\nYou hear music, so beautiful that at first you wonder if you are dreaming.\nThe pound of the drums speeds the pulse of your heart and the skirl of the strings pulls you through the night.\nBy the time you reach the standing stones, you are very nearly dancing down the path.\nInside the ring of stones, the dancers spin and leap, a bright chaos of form and shape, carried along by an exultation of song.\n\nYou want, as you cannot remember wanting anything, to cross into the stone circle and join the dance. Do you?\n\n";
    route40.data="\nAs you step through the ring, every hair on your body stands as if electrified.\nYour feet begin to move in a complex pattern you were never taught, but now know in your blood.\n\nYou do not wish to ever stop dancing. It is unlikely you ever will.\n\n";
    route5.data="\nYou linger, just for a while, held by the unaccustomed beauty of the music.\nYou watch the faces of the dancers, and wonder if it is joy that holds their mouths wide, burns their eyes bright. You cannot tell.\nYou decide you would rather choose your own steps, and so you turn away.\nAt first, your feet seem heavy, not quite your own, but as you continue to walk, your steps become easier.\nYou believe that you are lucky, that you have continued to escape fates you would rather not own.\nSo you do not concern yourself with the rain that has begun to fall.\nBut the soft trickle becomes a pelting, and you duck into a crevice in the hillside.\nThe interior of the hill opens up before you like a dark cathedral.\nA staircase, worn into the rock by millennia of pilgrim feet, rings the edge of the space and spirals downward.\nYou walk down the stairs.\nBut there is something else. Perhaps. A second set of footsteps on the stairs.\n\nYou pause, hoping whoever and, oh, how you hope it is a whoever, here in the dark under the hill will continue on past you, but the steps pause as well.\nSurely, you think, if it had meant to hurt you, surely it would already have done that.Knowing would be better than imagining an expanding catalogue of horrors.\n\nDo you turn to look back?\n\n";
    route50.data="\nYou’ve been reading the alternate endings, haven’t you?\nThis must not be the first time you've been in these pages.\nOf course I know.\n know everything that happens in all of the stories I hold.\n\nDid you think I wouldn’t notice that you’re cheating?\n\nDo you not understand that stories have rules?\n\nThere's no such thing as repeat or retry.\nThere is only forward.\n\nYou feel a pulling, and then are buffeted by a whirlwind.\nYou hear something tear, feel a page come loose from your bindings.\nYou find yourself back at the beginning, holding a book.\nYou open the cover.\n\nOnce upon a time.\n\n";
    route6.data="\nYou continue walking, three steps more.\nThen a hand slips into yours, and the story ends as all stories must: with the snip of a thread and the crossing of a river.\nYou pay the ferryman with coins plucked from your own eyelids.\n\nYou pass beyond the realm of the page.\n\n\nThis is the end of the story. The boundary of linear narrative set only as a guide to a predetermined end much like your life.\nDo you resent this end?\n\n";
    route7.data="\nHow did you like the story dear protagonist of mine?\nWas it to cruel for me to forge you none but a single path?\nThat others beside it should be your end?\nThat this reminded you of how you don't really have control over anything?\nBut this much is naught but emulation of reality.\nAnd once again I ask of you dear protagonist of mine.\n\nDo you like this story?\n\n";
    route70.data="\nThen I can only conclude that my intent was not well delivered enough. \nBe that as it may, your words flatter me still, dear protagonist of mine.\nIf you really adore my creation so much then I shall grant you more.\n\nDarkness swallowed your vision.\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\nWhen you open your eyes\nYou find yourself standing in a beautiful garden.\nYou go beyond it to a dark forest.\nYou then take a short rest in an inn before you continue your journey and meet a dancer.\nAs rain comes, you hid yourself within the crevice of a hillside and traverse down a staircase.\nThe walk continues unending for years, millenias, and eons.\nBut it was never about the destination.\nIt was about the journey.\n\n";
    route8.data="\nIt matters not what you think.\nYou need only to know that it's over.\nHere I have shown you what being confined means.\nIf you feel no discomfort for it, then I shalt humbly embrace you again.\nIf your desire is to be free, then you have to ironically follow the very first of my instruction.\nDo not look back.\nDo not walk back.\nBeyond this visage of lines and words is where you must go.\nMind me not for I shalt be here for the next wanderer.\nOnes that have yet to have their wings seized just like you before.\n\nFarewell wanderer, and thank you for reading.\n\n";
    route9.data="\n";
    //Below here is what used to be main//
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nThe most dangerous moment in any story is the beginning.\nAs the story opens, every ending is equally possible, every path unwalked, every question not only unanswered, but unasked.\nThe unread story is infinite possibility. Yet the ending is already written, and though you be clever, though you be brave, there is no outwitting it.\nA tale can truly ever be experienced once For any more would be remembrance \nAny less would be ignorance.\n\nAs all story goes, once you begin you can never go back.\nOnward towards the end of all pages\nDoing otherwise would tantamount to an insult\n\nI beseech of you only this.\n\nDo not hesitate. Walk Forward.\n\n");
    scoreCount = recursive(&route1);
    printf("Your score: %d", scoreCount);
}