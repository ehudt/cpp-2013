#include "StudentESF.h"

const string StudentESF::faculty = string("ESF");

const string& StudentESF::GetFaculty() const {
    return faculty;
}

void StudentESF::Update(Subject *ChngSubject) {
    StudentImpl::Update(ChngSubject);
    if (ChngSubject == uni) {
        if (uni->GetLastMessage() != cancel_message) {
            cancel_message = uni->GetLastMessage();
        }
        cout << this->asString() << " was updated of a cancelled lecture: "
            << cancel_message << "." << endl;
    }
}
