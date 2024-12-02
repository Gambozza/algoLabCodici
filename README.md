# algoLabCodici
Mega file occhi blu finale con le principali strutture/firme/ecc.. che il prof ha detto che spesso chiede all'esame in modo da averle tutte in un posto

# Comandi essenziali per aggiornare/caricare un file in una repository Git
#FAI QUESTI COMANDI CON GIT BASH, NELLA CARTELLA CON I FILE, PER CARICARLI NELLA REPOSITORY

| **Comando**                     | **Descrizione**                                                                                   |
|---------------------------------|---------------------------------------------------------------------------------------------------|
| `git status`                    | Controlla lo stato del repository: file modificati, non tracciati o pronti per il commit.        |
| `git add <nome_file>`           | Aggiunge un file specifico alla staging area.                                                    |
| `git add .`                     | Aggiunge **tutti i file modificati** o nuovi alla staging area.                                  |
| `git commit -m "messaggio"`     | Crea un commit con un messaggio descrittivo delle modifiche.                                     |
| `git pull`                      | Scarica le modifiche dal repository remoto (utile prima di fare il push per evitare conflitti).  |
| `git push`                      | Carica i commit locali sul branch remoto.                                                       |

---


# Comandi principali di Git

Di seguito trovi una lista dei comandi principali di Git per gestire modifiche, commit e sincronizzazione con un repository remoto.

## Stato e modifica dei file
| **Comando**                   | **Descrizione**                                                                                   |
|-------------------------------|---------------------------------------------------------------------------------------------------|
| `git status`                  | Mostra lo stato del repository: file modificati, non tracciati o pronti per il commit.           |
| `git add <file>`              | Aggiunge un file specifico alla staging area (pronto per il commit).                             |
| `git add .`                   | Aggiunge **tutti** i file modificati e non tracciati alla staging area.                         |
| `git commit -m "messaggio"`   | Crea un commit locale con un messaggio descrittivo delle modifiche.                             |
| `git commit -am "messaggio"`  | Aggiunge **e** committa in un solo passaggio (solo per file già tracciati).                     |
| `git log`                     | Mostra la cronologia dei commit effettuati nel repository locale.                                |
| `git log --oneline`           | Mostra la cronologia dei commit in una vista compatta (una riga per commit).                     |
| `git diff`                    | Mostra le differenze tra i file modificati e l'ultima versione committata.                      |
| `git diff <file>`             | Mostra le differenze per un file specifico.                                                      |
| `git reset <file>`            | Rimuove un file dalla staging area (senza eliminarlo dal disco).                                |
| `git reset --hard`            | Annulla **tutte** le modifiche locali (attenzione: perdi le modifiche non salvate).             |
| `git rm <file>`               | Rimuove un file dal repository e lo elimina anche dalla directory locale.                       |
| `git mv <vecchio> <nuovo>`    | Rinomina o sposta un file nel repository.                                                       |

---

## Sincronizzazione con il repository remoto
| **Comando**                   | **Descrizione**                                                                                   |
|-------------------------------|---------------------------------------------------------------------------------------------------|
| `git push`                    | Carica i commit locali sul repository remoto (es. GitHub).                                       |
| `git pull`                    | Scarica e integra le modifiche dal repository remoto nel repository locale.                      |
| `git fetch`                   | Scarica le modifiche dal repository remoto **senza integrarle** (usa `git merge` per applicarle).|
| `git clone <URL>`             | Clona un repository remoto (crea una copia locale).                                              |

---

## Gestione dei branch
| **Comando**                   | **Descrizione**                                                                                   |
|-------------------------------|---------------------------------------------------------------------------------------------------|
| `git branch`                  | Mostra tutti i branch nel repository.                                                            |
| `git branch <nome>`           | Crea un nuovo branch con il nome specificato.                                                    |
| `git checkout <branch>`       | Passa a un branch specifico.                                                                     |
| `git merge <branch>`          | Unisce il branch specificato con quello attuale.                                                 |
| `git branch -d <branch>`      | Elimina un branch locale (solo se è stato già unito).                                            |

---

Questo elenco contiene i comandi principali per iniziare a utilizzare Git in modo efficace. Per ulteriori dettagli o domande, consulta la [documentazione ufficiale di Git](https://git-scm.com/doc).

# Vocabolario Git

Ecco un elenco dei principali termini utilizzati in Git con i loro significati.

## Termini principali

| **Termine**         | **Significato**                                                                                             |
|---------------------|-----------------------------------------------------------------------------------------------------------|
| **Repository**      | Una "cartella speciale" dove Git tiene traccia delle modifiche ai file. Può essere locale (sul tuo computer) o remoto (su GitHub). |
| **Commit**          | Un punto di salvataggio nel tempo che registra le modifiche fatte al progetto, accompagnato da un messaggio descrittivo. |
| **Branch**          | Una "ramificazione" indipendente del progetto. Permette di lavorare su nuove funzionalità senza influenzare il branch principale (es. `main`). |
| **Merge**           | L'unione di due branch in uno solo, applicando le modifiche di un branch a un altro.                       |
| **Staging Area**    | Una "zona temporanea" dove vengono messe le modifiche che vuoi includere nel prossimo commit.               |
| **Working Directory** | La cartella sul tuo computer dove stai effettivamente lavorando e modificando i file.                     |
| **Remote**          | Un repository ospitato su un server remoto (es. GitHub), con cui puoi sincronizzarti tramite `push` e `pull`. |
| **Push**            | Carica i commit dal repository locale a quello remoto (es. da Git sul tuo computer a GitHub).              |
| **Pull**            | Scarica le modifiche dal repository remoto e le unisce al repository locale.                               |
| **Clone**           | Crea una copia locale di un repository remoto (scarica il repository sul tuo computer).                    |
| **Fetch**           | Scarica le modifiche dal repository remoto **senza integrarle** automaticamente (serve `merge` per unirle). |
| **Diff**            | Mostra le differenze tra due versioni di un file o di un repository (es. file modificati rispetto al commit precedente). |
| **Checkout**        | Cambia il branch attivo o ripristina una versione specifica di un file.                                     |
| **Reset**           | Rimuove modifiche dalla staging area o annulla commit locali.                                              |
| **HEAD**            | Un puntatore che indica il commit o il branch attualmente attivo nel repository.                           |
| **Master/Main**     | Il branch predefinito di un repository (oggi si usa spesso `main` al posto di `master`).                   |
| **Tag**             | Un'etichetta associata a un commit specifico, spesso usata per segnare versioni di rilascio (es. `v1.0`).   |
| **Conflict**        | Un conflitto che si verifica quando due persone modificano lo stesso file nello stesso punto, e Git non può risolverlo automaticamente. |
| **Origin**          | Nome predefinito che Git assegna al repository remoto collegato al progetto.                               |
| **Untracked**       | File presenti nella directory di lavoro, ma non ancora tracciati da Git.                                   |
| **Tracked**         | File che Git sta già monitorando e che fanno parte della cronologia del repository.                        |
| **Fast-Forward**    | Un tipo di merge semplice dove un branch è "avanzato" fino a coincidere con un altro, senza creare nuovi commit. |

---

### **Esempio pratico**
1. Quando inizi a lavorare su un progetto, crei un **repository**.
2. Modifichi i file nella tua **working directory**.
3. Aggiungi le modifiche alla **staging area** con il comando `git add`.
4. Salvi queste modifiche nel repository con un **commit**.
5. Se vuoi condividere il tuo lavoro, usi `git push` per caricarlo su un repository **remoto** (es. GitHub).
6. Se qualcuno modifica i file sul repository remoto, usi `git pull` per sincronizzarti e scaricare le modifiche.
7. Se lavori su una nuova funzionalità, crei un nuovo **branch** (es. `nuova-funzionalità`) e poi lo **merge** nel branch principale (`main`).

---

