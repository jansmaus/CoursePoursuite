#include "notaire.h"
#include "Exception/notaireexceptiondecisiondejavue.h"

Notaire::Notaire():fuyardDecision(nullptr),poursuivantDecision(nullptr)
{
}

Notaire::~Notaire()
{
    if (fuyardDecision!=nullptr)
        delete fuyardDecision;
    if (poursuivantDecision!=nullptr)
        delete poursuivantDecision;
}

Notaire::Notaire(const Notaire& notaire):fuyardDecision(nullptr),poursuivantDecision(nullptr)
{
    if (notaire.fuyardDecision!=nullptr)
        this->fuyardDecision=new Position(*notaire.fuyardDecision);
    if (notaire.poursuivantDecision!=nullptr)
        this->poursuivantDecision=new Position(*notaire.poursuivantDecision);
}

Position Notaire::getFuyardDecision()const
{
    if (fuyardDecision!=nullptr)
        return *fuyardDecision;
    else
        throw NotaireExceptionAucuneDecision("La décision du fuyard n'est pas encore enregistrée.",__LINE__);
}

Position Notaire::getPoursuivantDecision()const
{
    if (poursuivantDecision!=nullptr)
        return *poursuivantDecision;
    else
        throw NotaireExceptionAucuneDecision("La décision du poursuivant n'est pas encore enregistrée.",__LINE__);
}

void Notaire::setFuyardDecision(const Position& p)
{
    if (fuyardDecision!=nullptr)
        throw NotaireExceptionDecisionDejaVue("La décision du fuyard est déjà enregistrée.",__LINE__);
    fuyardDecision=new Position(p);
}

void Notaire::setPoursuivantDecision(const Position& p)
{
    if (poursuivantDecision!=nullptr)
        throw NotaireExceptionDecisionDejaVue("La décision du poursuivant est déjà enregistrée.",__LINE__);
    poursuivantDecision=new Position(p);
}

bool Notaire::tourValide()const
{
    if (fuyardDecision!=nullptr && poursuivantDecision!=nullptr)
        return true;
    else
        return false;
}

void Notaire::raz()
{
    if (fuyardDecision!=nullptr)
    {
        delete fuyardDecision;
        fuyardDecision=nullptr;
    }
    if (poursuivantDecision!=nullptr)
    {
        delete poursuivantDecision;
        poursuivantDecision=nullptr;
    }
}

Notaire& Notaire::operator =(const Notaire& notaire)
{
    this->raz();

    if (notaire.fuyardDecision!=nullptr)
        this->fuyardDecision=new Position(*notaire.fuyardDecision);
    if (notaire.poursuivantDecision!=nullptr)
        this->poursuivantDecision=new Position(*notaire.poursuivantDecision);

    return *this;
}
