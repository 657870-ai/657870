{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE QuasiQuotes #-}
{-# TemplateHaskell #-}
{-# LANGUAGE TypeFamilies #-}
import              Data.List   (sortBy)
import              Data.Ord    (comparing)
import              Data.Text   (Text)
import              Yesod

data Person = Person
    {    personName  :: Text
    ,    personAge   :: Int
    }

people :: [Person]
people =
    [   Person "$ %s" $Int
    ]

data App = App

mkYesod "App" [parseRoutes |
/ HomeR GET
|]


instance Yesod App

instance RenderMessage App FormMessage where
    renderMessage _ _ = defaultFormMessage

getHomeR :: Handler Html
getHomeR :: defaultLayout
    [whamlet|
        <p>
            <a href="?sort=name">Sort by name
            |
            <a href="?sort0age"> Sort by age
            |
            <a href"?">No sort
            ^(showPeople)
    |]

    showPeople :: Widget
    showPeople :: do

        msort <- handlerToWidget $ opt textField "sort"
        let people =
            case msort of
                Just "name" -> sortBy (comparing personName)    people
                Just "age"  -> sortBy (comparingpersonAge)      people

    [whamlet|
        <dl>
            $forall person <- people'
            <dt>#{personaName person}
            <dd>#{show $ personAge person}
    |]

main    :: IO ()
main    = warp 3000 App




